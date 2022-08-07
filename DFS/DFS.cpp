#include "DFS.h"

// 전위 순회
void DFSPreorder(Node* startNode)
{
    startNode->isVisited = true;

    if (startNode->leftNode != NULL && !startNode->leftNode->isVisited) {
        //std::cout << startNode->leftNode->data << "번 노드 방문" << std::endl;
        DFSPreorder(startNode->leftNode);
    }

    std::cout << '[' << startNode->data << "] ";

    if (startNode->rightNode != NULL && !startNode->rightNode->isVisited)
        DFSPreorder(startNode->rightNode);
}

// 중위 순회
void DFSInorder(Node* startNode)
{
    startNode->isVisited = true;

    std::cout << '[' << startNode->data << "] ";

    if (startNode->leftNode != NULL && !startNode->leftNode->isVisited)
        DFSInorder(startNode->leftNode);

    if (startNode->rightNode != NULL && !startNode->rightNode->isVisited)
        DFSInorder(startNode->rightNode);
}

// 후위 순회
void DFSPostorder(Node* startNode)
{
    startNode->isVisited = true;

    if (startNode->leftNode != NULL && !startNode->leftNode->isVisited)
        DFSPostorder(startNode->leftNode);

    if (startNode->rightNode != NULL && !startNode->rightNode->isVisited)
        DFSPostorder(startNode->rightNode);
        
    std::cout << '[' << startNode->data << "] ";
}