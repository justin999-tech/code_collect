#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Root(vector<int>& parent, int index) {
    if (parent[index] != index) {
        return parent[index] = Root(parent, parent[index]); 
    }
    else {
        return index;
    }
}

// 合併函式 (Union by Size)
void Union(vector<int>& parent, vector<int>& size, int i, int j) {
    if (size[i] >= size[j]) {
        parent[j] = i;        
        size[i] += size[j];   
        size[j] = 0;          
    }
    else {
        parent[i] = j;        
        size[j] += size[i];   
        size[i] = 0;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num_case;
    if (cin >> num_case) {
        while (num_case--) {
            int num_city, num_edge;
            cin >> num_city >> num_edge;

            vector<int> parent(num_city);
            vector<int> size(num_city, 1); // 預設每個城市自己一組，大小為 1

            for (int j = 0; j < num_city; j++) {
                parent[j] = j;
            }

            int num_connected = num_city; // 一開始有 N 個連通塊
            int connected_max = 1;        // 一開始最大連通塊只有 1 人

            for (int j = 0; j < num_edge; j++) {
                int a, b;
                cin >> a >> b;
                // 轉成 0-based
                a--; 
                b--;

                int root_a = Root(parent, a);
                int root_b = Root(parent, b);

                if (root_a != root_b) {
                    // 有效建橋：進行合併
                    Union(parent, size, root_a, root_b);

                    // 1. 連通塊數量少 1
                    num_connected--;

                    // 2. 檢查新合併出的那個群組，是不是目前最大的
                    // Union 後，root_a 或 root_b 其中一個的大小增加了，另一個變 0
                    // 我們只要看變大的那個有沒有超過目前的紀錄
                    int new_size = max(size[root_a], size[root_b]);
                    if (new_size > connected_max) {
                        connected_max = new_size;
                    }
                }

                // 題目要求：每加入一條邊都要輸出一次結果 (不管有沒有合併成功)
                cout << num_connected << " " << connected_max << "\n";
            }
        }
    }
    return 0;
}