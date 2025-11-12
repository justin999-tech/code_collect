#include <iostream>
using namespace std;

int data[14][2] = {{1, 2}, {2, 1}, {1, 5}, {5, 1},
                  {2, 3}, {3, 2}, {2, 4}, {4, 2},
                  {3, 4}, {4, 3}, {3, 5}, {5, 3},
                  {4, 5}, {5, 4}};

int main() {
    int numVertices = 5; // 有5個節點，從1到5
	
    // 創建一個陣列來存儲相鄰節點的內容
    int adjacentList[numVertices][numVertices] = {0};

    // 填充相鄰串列
    for (int i = 0; i < 14; i++) {
        int from = data[i][0];
        int to = data[i][1];
        adjacentList[from - 1][to - 1] = 1; // 1表示有邊相連
        adjacentList[to - 1][from - 1] = 1; // 因為是無向圖，所以需要兩邊都標記
    }

    // 輸出相鄰串列
    for (int i = 0; i < numVertices; i++) {
        cout << "節點 " << (i + 1) << " 的鄰接節點：";
        for (int j = 0; j < numVertices; j++) {
            if (adjacentList[i][j] == 1) {
                cout << (j + 1) << " ";
            }
        }
        cout << endl;
    }

    return 0;
}

