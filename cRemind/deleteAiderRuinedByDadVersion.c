#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>
#include<stdbool.h>
typedef struct FileNode {
  struct FileNode *next, *children;
  char *name;
  long long size;
  bool isDir;
} FileNode;



FileNode *scanDir(char *path) {
  FileNode *fn = calloc(sizeof(FileNode), 1);
  fn->name = strdup(path);
  struct stat st;
  //printf("Reading %s\n", path);
  if(stat(path, &st)){
    printf("Yeet \n");
    return fn;
  }
  if(S_ISDIR(st.st_mode)) {                       //if is directory
    DIR *dir = opendir(path);
    if(!dir) {
      fprintf(stderr, "OpenDir ");
      perror(path);
    }
    else{
      fn->isDir = true;
      //printf("\t found a DIR\n");
      for(struct dirent *de; de = readdir(dir); )
        if(de->d_name[0] != '.') {
          char name[strlen(path)+strlen(de->d_name)+2];
          strcpy(name, path);
          strcat(name, "/");
          strcat(name, de->d_name);
          FileNode *ch = scanDir(name);
          ch->next = fn->children;
          fn->children = ch;
          fn->size += ch->size;
        }
      //printf("\n--EndOfDir--\n");
      closedir(dir);
    }
  } else {                                        // if a reg file
    fn->size = st.st_size;
    fn->isDir = false;
    //printf("\t reg file, %d bytes\n", fn->size);
  }
  return fn;
}

void freeDir(FileNode *fn, long long orig, int percent) {
  if(fn) {
    long long cutoffPoint = orig * percent / 100;
    if(fn->size > orig * percent / 100 ){
      printf("%s", fn->name);
      printf(" <<<------------------------------------------------------------------------------------ DELET Dis\n");
    }
    freeDir(fn->children, orig, percent);
    freeDir(fn->next, orig, percent);
    free(fn->name);
    free(fn);
  }
}

int main(int argc, char *argv[]) {
  char *path = argc > 1 ? argv[1] : ".";
  FileNode *root = scanDir(path);
  freeDir(root, root->size, 5);

  return 0;
}
