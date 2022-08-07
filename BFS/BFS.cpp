#include "BFS.h"

void BFS(Node* root, Queue* pQueue)
{
    if (!pQueue->empty()) {
        Node* node = &root[pQueue->front()];
        node->isVisited = true;
        pQueue->pop();
        cout << '[' << node->data << "] ";

        if (node->leftNode != NULL && !node->leftNode->isVisited) {
            pQueue->push(node->leftNode->data);
            node->leftNode->isVisited = true;
        }

        if (node->rightNode != NULL && !node->rightNode->isVisited) {
            pQueue->push(node->rightNode->data);
            node->rightNode->isVisited = true;
        }
        
        if (!pQueue->empty())
            BFS(root, pQueue);
    }
}