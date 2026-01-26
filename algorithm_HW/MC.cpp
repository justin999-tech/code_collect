#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
// 設定一個非常大的數當作無限大
const long long INF = 1e18;
// 定義邊的結構
struct Edge {
    int to;         // 目標點 ID
    long long cap;  // 剩餘容量
    int rev;        // 反向邊的索引
};
// 【修改 1】改成全域 vector，但一開始不指定大小
// vector<vector<Edge>>: 外層 vector 存點，內層 vector 存該點連出去的邊
vector<vector<Edge>> adj;
// 【修改 2】level 也改成 vector
vector<int> level;
// 加邊函式
void add_edge(int from, int to, long long cap) {
    // 這裡操作跟原本一樣，因為 vector 也是用 push_back
    adj[from].push_back({to, cap, (int)adj[to].size()});
    adj[to].push_back({from, 0, (int)adj[from].size() - 1});
}
// BFS: 建立分層圖
bool bfs(int s, int t) {
    // 【修改 3】取代 fill(level, level + MAXN, -1)
    // .assign(大小, 數值): 把 vector 重設為指定大小，且每個位置都填入 -1
    // 這裡用 level.size() 保持原本的大小
    level.assign(level.size(), -1);
    level[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (const auto& edge : adj[v]) {
            if (edge.cap > 0 && level[edge.to] == -1) {
                level[edge.to] = level[v] + 1;
                q.push(edge.to);
            }
        }
    }  
    return level[t] != -1;
}
// DFS: 沿著分層圖推流
long long dfs(int v, int t, long long pushed) {
    if (pushed == 0) return 0;
    if (v == t) return pushed;
    for (auto& edge : adj[v]) {
        int tr = edge.to;
        if (level[v] + 1 != level[tr] || edge.cap == 0) continue;
        long long tr_pushed = dfs(tr, t, min(pushed, edge.cap));
        if (tr_pushed == 0) continue;
        edge.cap -= tr_pushed;
        adj[tr][edge.rev].cap += tr_pushed;
        return tr_pushed;
    }
    
    return 0;
}
// Dinic 主演算法
long long dinic(int s, int t) {
    long long flow = 0;
    while (bfs(s, t)) {
        while (long long pushed = dfs(s, t, INF)) {
            flow += pushed;
        }
    }
    return flow;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    if (!(cin >> n >> m)) return 0;
    int total_nodes = n + m + 2;
    // 初始化 adj: 開 total_nodes 個格子，每格放一個空的 vector<Edge>
    adj.assign(total_nodes, vector<Edge>());
    // 初始化 level: 開 total_nodes 個格子
    level.resize(total_nodes);
    vector<long long> revenues(n);
    long long total_revenue = 0;
    for (int i = 0; i < n; ++i) {
        cin >> revenues[i];
        total_revenue += revenues[i];
    }
    int source = 0;
    int sink = n + m + 1;
    // 1. 建圖：Source -> 產品
    for (int i = 0; i < n; ++i) {
        add_edge(source, i + 1, revenues[i]);
    }
    // 2. 建圖：產品 -> 工具
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        while (k--) {
            int tool_idx;
            cin >> tool_idx;
            add_edge(i + 1, n + tool_idx, INF);
        }
    }
    // 3. 建圖：工具 -> Sink
    for (int j = 0; j < m; ++j) {
        long long cost;
        cin >> cost;
        add_edge(n + 1 + j, sink, cost);
    }
    long long min_loss = dinic(source, sink);
    cout << total_revenue - min_loss << endl;
    return 0;
}