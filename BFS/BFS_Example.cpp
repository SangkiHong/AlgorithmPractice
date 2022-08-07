#include "BFS.h"

#define TREE_SIZE 21

int CalMaxLevel(int level, int sum, int size)
{
    if (sum < size)
        return CalMaxLevel(level + 1, sum + level + 1, size);
    else
        return level;
}

int main()
{
    Node* nodes = new Node[TREE_SIZE];
    Queue* pQueue = new Queue();
    int level = 1;
    int count = 1;
    int maxLevel = CalMaxLevel(1, 1, TREE_SIZE);

    // 노드 초기화
    for (int i = 0; i < TREE_SIZE; i++)
    {
        nodes[i].data = i;
        nodes[i].isVisited = false;
        if (level < maxLevel) {
            nodes[i].leftNode = &nodes[i + level];
            nodes[i].rightNode = &nodes[i + level + 1];
        }
        else {
            nodes[i].leftNode = NULL;
            nodes[i].rightNode = NULL;
        }

        count--;
        if (count == 0) {
            level++;
            count = level;
        }
    }

    // Example Tree
    //           0
    //         /    \
    //        1      2
    //      /  \   /   \
    //     3     4      5
    //    /  \ /   \  /   \
    //   6    7      8     9
    //  ...

    cout << "BFS Algorithm!" << endl;
    pQueue->push(0);
    BFS(nodes, pQueue);

    return 0;
}