#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
	struct node* childNodes[27]; // 0 is A, 1 is B ... 26 is null/terminator
	int depth;
	char* meaning;
	char* text;
}node;

void makeWord(node *root,char* word, char* meaning);
void prefixOf(node* parent, char* prefix);
node *makeNode(node *parent, int place);
void suffixes(node* parent);


void main(int argc, char** argv){
	node root;
	memset(&root, 0, sizeof(root));
	root.depth = 0;
	char* firstWord = "psycho";
	char secondWord[] = {'p','s','y','c','h','o','t','h','e','r','a','p','i','s','t',0};
	char thirdWord[] = "psychoh";

	makeWord(&root, firstWord, "Insane");
	//printf("\n");
	makeWord(&root, secondWord, "To treat Insane");
	//printf("\n");
	makeWord(&root, "newer", "Not as old");
	//printf("\n");
	prefixOf(&root, thirdWord);
	printf("\n\n");
	prefixOf(&root, "psy");
	printf("\n\nAll words:");
	suffixes(&root);


	printf("\n");return;
}

node *makeNode(node *parent, int place){
	node *n = malloc(sizeof(node));
	memset(n, 0, sizeof(node));
	parent->childNodes[place] = n;
	n->depth = parent->depth + 1;

}

void makeWord(node *root,char* word, char* meaning){
	node *tmp = root;
	for(int i  =0;i < strlen(word);i++){
		int currChar = word[i]-'a';
		if(currChar < 0 || currChar > 26)
			continue;
		if(tmp->childNodes[currChar] == NULL){
				tmp->childNodes[currChar] = makeNode(tmp, currChar);


				//printf(/*""[%d]:"*/ "[%2d]", currChar);



			}
		else{

			//printf("[XX]");

		}
		tmp = tmp->childNodes[currChar];

	}
	tmp->childNodes[26] = tmp; // terminator
	tmp->meaning = meaning;
	tmp->text = word;

}
void prefixOf(node* root,char* prefix){
//	boolean done = False;
	int currChar=0;
	node* currNode = root;
	while(currChar < strlen(prefix)){


		//printf("[%2d]", prefix[currChar] - 'a');



		// set currrNode to it's childNode pointer indexed at it's alphabetical position.
		currNode = currNode->childNodes[prefix[currChar++] - 'a'];
		if(currNode == NULL){
			//all that end with where it was left off
			//the word inputted doesn't exist as a prefix
			printf("Nothing begins with '%s'", prefix);
			//printf("--word broke--\n");

			return;
		}
	}
	//recursive thing to look at all endings which lead somewhere
	printf("endings of(%s): ", prefix);
	suffixes(currNode);
}

void suffixes(node* parent){
	node* tmp = parent;
	for(int i = 0; i < 25; i++){
		if(parent->childNodes[i] != NULL){
			tmp = parent->childNodes[i];
			//printf("[%2d]", i);
			suffixes(tmp);
		}

	}
	if(parent->childNodes[26] !=NULL){
		//printf("\nIs Word");
		printf("'%s' ",parent->text);
	}

}
