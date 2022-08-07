#include <stdio.h>
#include <iostream>

typedef struct _tagNode
{
    int data;
    bool isVisited;
    _tagNode* leftNode;
    _tagNode* rightNode;
} Node;

void DFSPreorder(Node* startNode);
void DFSInorder(Node* startNode);
void DFSPostorder(Node* startNode);