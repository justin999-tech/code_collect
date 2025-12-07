#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000; 
// 輸出第 t 次迭代的距離表
void printTable(const vector<vector<int>>& dist, int t) {
    int n = (int)dist.size();
    cout << "t = " << t << "\n";

    // 欄位標頭 (A, B, C, ...)
    cout << "    ";
    for (int j = 0; j < n; ++j) {
        char label = 'A' + j;
        cout << setw(4) << label;
    }
    cout << "\n";
    // 每一列
    for (int i = 0; i < n; ++i) {
        char rowLabel = 'A' + i;
        cout << rowLabel << "   ";
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] >= INF / 2) {
                cout << setw(4) << "INF";
            } else {
                cout << setw(4) << dist[i][j];
            }
        }
        cout << "\n";
    }
    cout << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<vector<int>> base(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            string token;
            cin >> token;

            // 用字串 "INF" / "inf" 表示 ∞
            if (token == "INF" || token == "inf" || token == "Inf") {
                base[i][j] = INF;
            } else {
                int val = stoi(token);
                if (val < 0) base[i][j] = INF;
                else base[i][j] = val;
            }
        }
    }

    // cur = 目前各節點的 distance vector (一開始是 t=0)
    vector<vector<int>> cur = base;
    int maxIter = n - 1; // 最多需要 n-1 次 (Bellman-Ford 的上界)
    for (int t = 1; t <= maxIter; ++t) {
        vector<vector<int>> nxt = cur; 

        // 對每個「來源 i」和「目的 j」做 Bellman-Ford 的更新
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int best = cur[i][j];
                for (int k = 0; k < n; ++k) {
                    if (base[i][k] >= INF / 2) continue;   
                    if (cur[k][j] >= INF / 2) continue;   

                    int cand = base[i][k] + cur[k][j];
                    if (cand < best) best = cand;
                }
                nxt[i][j] = best;
            }
        }
        if (nxt == cur) break;
        printTable(nxt, t);
        cur.swap(nxt);
    }

    return 0;
}
