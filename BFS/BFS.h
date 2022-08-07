#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

typedef queue<int> Queue;

typedef struct _tagNode
{
    int data;
    bool isVisited;
    _tagNode* leftNode;
    _tagNode* rightNode;
} Node;

void BFS(Node* root, Queue* queue);