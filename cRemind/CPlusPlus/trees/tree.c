#include "tree.h"
#include <assert.h>

Node *genTree(int startID, int size) {
    if(size < 1) return NULL;
    Node *ret = malloc(sizeof(Node));
    ret->id = startID++;
    int half = --size / 2;
    ret->l = genTree(startID, half);
    ret->r = genTree(startID+half, size-half);
    return ret;
}

void writeCsv(FILE *f, Node *tree) {
    if(tree == NULL) return;
    writeCsv(f, tree->l);
    writeCsv(f, tree->r);
    fprintf(f, "%d,%d,%d\n", tree->id,
            tree->l ? tree->l->id : -1,
            tree->r ? tree->r->id : -1);
}

void writeXml(FILE *f, Node *tree) {
    if(tree == NULL) return;
    fprintf(f, "<n%d> ", tree->id);
    writeXml(f, tree->l);
    writeXml(f, tree->r);
    fprintf(f, " </n%d>", tree->id);
}

#ifdef SOLUTION

typedef struct Triple {
    int id, l, r;
    struct Triple *next;
} Triple;

static Node *makeNode(Triple *data, int id) {
    if(id >= 0)
        for(Triple *line=data; line; line=line->next)
            if(line->id == id) {
                Node *n = malloc(sizeof(Node));
                n->id = id;
                n->l = makeNode(data, line->l);
                n->r = makeNode(data, line->r);
                return n;
            }
    return NULL;
}

Node *readCsv(FILE *f) {
    Triple *ptr, tmp;

    while(!feof(f))
        if(3 == fscanf(f, "%d,%d,%d", &tmp.id, &tmp.l, &tmp.r)) {
            tmp.next = ptr;
            ptr = malloc(sizeof(tmp));
            *ptr = tmp;
        }

    Node *ret = makeNode(ptr, ptr->id);

    while(ptr) {
        tmp = *ptr;
        free(ptr);
        ptr = tmp.next;
    }

    return ret;
}

static void freeTree(Node *tree) {
    if(tree) {
        freeTree(tree->l);
        freeTree(tree->r);
        free(tree);
    }
}

typedef struct Found {
    Node *result;
    int gotA, gotB;
} Found;
/*
static int searchA(Node *tree, int a) {
    if(tree == NULL)   return 0;
    if(tree->id == a)  return 1;
    return searchA(tree->l, a) || searchA(tree->r, a);
}

static Found searchAB(Node *tree, int a, int b) {
    Found ret = {NULL, 0, 0};

    if(!tree)
        return ret;

    if(tree->id == a) {
        ret.gotA = 1;
        if(searchA(tree, b)) {
            ret.gotB = 1;
            ret.result = tree;
        }
        return ret;
    }
    if(tree->id == b) {
        ret.gotB = 1;
        if(searchA(tree, a)) {
            ret.gotA = 1;
            ret.result = tree;
        }
        return ret;
    }

    Found rl = searchAB(tree->l, a, b);
    if(rl.gotA) {
        if(rl.gotB)
            return rl;

        if(searchA(tree->r, b)) {
            rl.gotB = 1;
            rl.result = tree;
            return rl;
        }
    }

    Found rr = searchAB(tree->r, a, b);
    if(rr.gotA) {
        if(rr.gotB)
            return rr;

        if(searchA(tree->l, b)) {
            rr.gotB = 1;
            rr.result = tree;
            return rr;
        }
    }

    ret.gotA = (rl.gotA || rr.gotA); 
    ret.gotB = (rl.gotB || rr.gotB);
    if(ret.gotA && ret.gotB)
        ret.result = tree;

    return ret;
}

static Node *findAncestor(Node *tree, int a, int b) {
    Found f = searchAB(tree, a, b);
    return (f.gotA && f.gotB) ? f.result : NULL;
}
*/
#endif // SOLUTION

static void help() {
    printf("Args:\n"
           "\t-h\tThis message\n"
           "\t-g N\tGenerate a deterministic tree of N nodes\n"
           "\t-c\tPrint tree to stdout as CSV\n"
           "\t-x\tPrint tree to stdout as XML\n"
           "\t-f A B\tFind common ancestor of nodes A and B\n"
           "\nOperations that need a tree will read from stdin as CSV, unless it was generated already\n");
    exit(-1);
}

int main(int argc, char **argv) {
    if(argc < 2)
        help();

    Node *tree = NULL;
    for(int arg=1; arg<argc; arg++)
        if(argv[arg][0] == '-')
            switch(argv[arg][1]) {
                case 'g':
                    freeTree(tree);
                    tree = genTree(0, atoi(argv[++arg]));
                    break;
                case 'c':
                    if(!tree) tree = readCsv(stdin);
                    writeCsv(stdout, tree);
                    break;
                case 'x':
                    if(!tree) tree = readCsv(stdin);
                    writeXml(stdout, tree);
                    break;
                case 'f': {
                    if(!tree) tree = readCsv(stdin);
                    int a = atoi(argv[++arg]);
                    int b = atoi(argv[++arg]);
                    Node *n = findAncestor(tree, a, b);
                    if(n == NULL)
                        printf("Ancestor of %d and %d was not found\n", a, b);
                    else
                        printf("Ancestor of %d and %d is %d\n", a, b, n->id);
                    break;
                }
                case 'h':
                default:
                    help();
            }
        else
            help();

    freeTree(tree);
}
