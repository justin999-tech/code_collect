#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 容量用 int 就夠了 (因為這題流量都是 1)，但為了跟你之前的 code 保持一致，我留著 long long
const long long INF = 1e18;

// 邊的結構
struct Edge {
    int to;         // 目標點
    long long cap;  // 剩餘容量
    int rev;        // 反向邊索引
};

// 全域 vector
vector<vector<Edge>> adj;
vector<int> level;

// 加邊函式
void add_edge(int from, int to, long long cap) {
    adj[from].push_back({to, cap, (int)adj[to].size()});
    adj[to].push_back({from, 0, (int)adj[from].size() - 1});
}

// BFS: 建立分層圖
bool bfs(int s, int t) {
    // 重設 level，大小保持與總點數一致
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

// DFS: 推流 (無 ptr 優化版)
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
    // 優化 I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; // n: 左邊點數, m: 右邊點數
    if (!(cin >> n >> m)) return 0;

    // 節點編號規劃：
    // Source: 0
    // 左邊 U (1 ~ n): 保持 1 ~ n
    // 右邊 V (1 ~ m): 映射到 n+1 ~ n+m (避免編號衝突)
    // Sink: n + m + 1
    int source = 0;
    int sink = n + m + 1;
    int total_nodes = sink + 1;

    // 初始化 vector 大小
    adj.assign(total_nodes, vector<Edge>());
    level.resize(total_nodes);

    //初始化: vector<int> v(5); (创建 5 个 0) vs v.resize(5, 10); (创建 5 个 10).
    //截断/扩展: v.resize(3); 移除最后 2 个元素；v.resize(8, 0); 添加 3 个 0. 

    // 1. 建立 Source -> 左邊 U 的邊 (容量 1)
    // 同時讀取每個 U 的鄰居
    for (int i = 1; i <= n; ++i) {
        add_edge(source, i, 1); // Source 連到 U[i]

        int k; 
        cin >> k; // 讀取 U[i] 有幾個鄰居
        while (k--) {
            int v; 
            cin >> v;
            // 建立 左邊 U[i] -> 右邊 V[v] 的邊 (容量 1)
            // 右邊的 v 要加上 n 才是我們實際的編號
            add_edge(i, n + v, 1);
        }
    }

    // 2. 建立 右邊 V -> Sink 的邊 (容量 1)
    for (int j = 1; j <= m; ++j) {
        add_edge(n + j, sink, 1);
    }

    // 3. 計算最大流 (即最大匹配數)
    long long max_matching = dinic(source, sink);
    
    // 輸出最大匹配數量
    cout << max_matching << "\n";

    // 4. 輸出匹配的邊
    // 遍歷左邊的所有點 (1 ~ n)
    for (int i = 1; i <= n; ++i) {
        for (const auto& edge : adj[i]) {
            // 如果這條邊是連向右邊的點 (編號在 n+1 ~ n+m 之間)
            // 且 剩餘容量 (cap) 變成 0，代表這條邊被選中了 (有流量經過)
            //可以用edges.cap==0判讀的原因是因為一開始所有edges都被設成1
            if (edge.to > n && edge.to <= n + m && edge.cap == 0) {
                // 輸出原始編號：左邊 i, 右邊 edge.to - n
                cout << i << " " << edge.to - n << "\n";
                // 每個左邊的點只會匹配一個，找到就跳出內層迴圈
                break; 
            }
        }
    }

    return 0;
}