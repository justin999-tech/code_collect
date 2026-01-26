#include <iostream>
#include <vector>
#include <queue>
//用bellman會超時，所以用修正版的dijksra處理有向圖
using namespace std;
using pii = pair<long long, int>;
const long long INF = -1; 
int main() {
    // 1. 加速輸入輸出
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0; 

    vector<vector<pair<int, int>>> adj(n + 1);

    // 直接宣告大小為 n + 1，並將所有值預設為 INF (-1)
    vector<long long> dists(n + 1, INF);

    // 2. 讀取圖形資料
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w; 
        // 存入鄰接表：{權重, 目標點}
        adj[u].push_back({w, v}); 
    }

    // 3. Dijkstra 主邏輯
    // 宣告最小堆積 (Min-Heap)
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    // 定義 pair：first 放距離 (long long), second 放點編號 (int)
    dists[1] = 0; 
    pq.push({0, 1});

    while (!pq.empty()) {
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // 懶惰刪除：如果這個距離比已知的還大，就跳過
        // 注意 INF 是 -1，所以判斷邏輯是：如果已經有合法距離(不是-1) 且當前距離更長，則跳過
        if (dists[u] != INF && d > dists[u]) continue;

        for (auto& edge : adj[u]) {
            int w = edge.first;  // 權重
            int v = edge.second; // 目標點

            // 鬆弛操作：如果 v 還沒到過 (INF) 或 找到更短路徑
            if (dists[v] == INF || dists[u] + w < dists[v]) {
                dists[v] = dists[u] + w;
                pq.push({dists[v], v});
            }
        }
    }

    
    for (int i = 2; i <= n; ++i) {
        // 如果是最後一個數，後面不加空格，否則加空格
        cout << dists[i] << (i == n ? "" : " ");
    }
    cout << "\n";
    return 0;
}