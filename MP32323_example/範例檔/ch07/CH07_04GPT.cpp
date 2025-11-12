#include <iostream>

using namespace std;

const int MAX_NODES = 8;  // 圖形中節點的最大數量

int Data[20][2] =  
   { {1,2},{2,1},{1,3},{3,1},{2,4},{4,2},{2,5},{5,2},{3,6},{6,3},
   {3,7},{7,3},{4,5},{5,4},{6,7},{7,6},{5,8},{8,5},{6,8},{8,6} };

// 節點結構
struct Node {
    int value;
    Node* next;
};

// 圖形的鄰接串列
Node* adjacencyList[MAX_NODES] = {nullptr};

// 建立圖形的鄰接串列
void createAdjacencyList() {
    for (int i = 0; i < 20; i++) {
        int from = Data[i][0];
        int to = Data[i][1];
        
        // 創建新節點
        Node* newNode = new Node;
        newNode->value = to;
        newNode->next = nullptr;

        // 將新節點加入鄰接串列
        if (adjacencyList[from - 1] == nullptr) {
            adjacencyList[from - 1] = newNode;
        } else {
            Node* current = adjacencyList[from - 1];
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
}

// 先深後廣法（DFS）
void DFS(int node, bool visited[]) {
    if (!visited[node - 1]) {
        visited[node - 1] = true;
        cout << node << " ";
        Node* current = adjacencyList[node - 1];
        while (current != nullptr) {
            int neighbor = current->value;
            DFS(neighbor, visited);
            current = current->next;
        }
    }
}

int main() {
    createAdjacencyList();

    // 列出圖形的鄰接串列內容
    cout << "圖形的鄰接串列內容：" << endl;
    for (int i = 0; i < MAX_NODES; i++) {
        cout << "節點 " << (i + 1) << ": ";
        Node* current = adjacencyList[i];
        while (current != nullptr) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }

    // 執行DFS從節點1開始
    bool visited[MAX_NODES] = {false};
    cout << "DFS 遍歷結果：";
    DFS(1, visited);
    cout << endl;

    return 0;
}

