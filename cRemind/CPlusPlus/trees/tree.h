#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int id;
    struct Node *l, *r;
} Node;

Node *genTree(int startID, int size);
Node *readCsv(FILE *f);
void writeXml(FILE *f, Node *tree);

#endif
