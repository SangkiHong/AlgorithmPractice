#include "DFS.h"

int main()
{
    Node nodes[10];

    for (int i = 0; i < 10; i++) {
        nodes[i].data = i;
        nodes[i].isVisited = false;
        nodes[i].leftNode = NULL;
        nodes[i].rightNode = NULL;
    }
    
    //Example Node Link
    // [0]
    //  |  \
    // [1]-[2]-[3]-[8]
    //  |   |   |     \
    // [4]-[5] [6]-[7]-[9]

    nodes[0].leftNode = &nodes[1];
    nodes[0].rightNode = &nodes[2];
    nodes[1].leftNode = &nodes[2];
    nodes[1].rightNode = &nodes[4];
    nodes[2].leftNode = &nodes[5];
    nodes[2].rightNode = &nodes[3];
    nodes[3].leftNode = &nodes[6];
    nodes[3].rightNode = &nodes[8];
    nodes[4].rightNode = &nodes[5];
    nodes[6].rightNode = &nodes[7];
    nodes[7].rightNode = &nodes[9];
    nodes[8].rightNode = &nodes[9];

    std::cout << "DFS 전위 순회" << std::endl;
    DFSPreorder(&nodes[0]);
    std::cout << std::endl;
    // Result: [5] [2] [6] [7] [9] [3] [8] [1] [4] [0]

    // 방문 초기화
    for (int i = 0; i < 10; i++)
        nodes[i].isVisited = false;

    std::cout << "DFS 중위 순회" << std::endl;
    DFSInorder(&nodes[0]);
    std::cout << std::endl;
    // Result: [0] [1] [2] [5] [3] [6] [7] [9] [8] [4]

    // 방문 초기화
    for (int i = 0; i < 10; i++)
        nodes[i].isVisited = false;

    std::cout << "DFS 후위 순회" << std::   endl;
    DFSPostorder(&nodes[0]);
    std::cout << std::endl;
    // Result: [5] [9] [7] [6] [8] [3] [2] [4] [1] [0]

    return 0;
}
