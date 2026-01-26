#include<bits/stdc++.h>
using namespace std;

// 題目只要求輸出權重總和，不需要紀錄邊的結構，因此將 ResultEdge 移除以簡化程式

void primMST(int n, const vector<vector<pair<int,int>>>& adj){
    // Min-Priority Queue: <權重, 目前點, 來源點>
    // 使用 greater 讓它變成 Min-Heap (權重小的在上面)
    priority_queue< tuple<int,int,int> , vector<tuple<int,int,int>> , greater<tuple<int,int,int>> > pq;
    
    // 因為題目是 1-based (點編號 1~n)，所以這裡開 n+1 的大小比較直觀
    vector<bool> visited(n + 1, false);
    
    long long sum = 0;

    // 從頂點 1 開始 (題目 index 1~n)：權重 0, 目前點 1, 來源點 -1
    pq.push({0, 1, -1}); 

    while(!pq.empty()){
        auto[weight, curr, parent] = pq.top();
        pq.pop();

        if(visited[curr])
            continue;

        visited[curr] = true;
        
        sum += weight;

        for(const auto& neighbor : adj[curr]){
            int next_node = neighbor.first;
            int to_neighbor_weight = neighbor.second;

            if(!visited[next_node]){
                pq.push({to_neighbor_weight, next_node, curr});
            }
        }
    }

    // 題目要求只輸出一個總權重的數字 (64-bit integer)
    cout << sum << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    // 1. 依照題目讀取 n (點數) 和 m (邊數)
    if(!(cin >> n >> m)) return 0;

    // 2. 因為點編號是 1~n，大小設為 n+1 方便直接操作
    //pair<to,weight>;
    vector<vector<pair<int,int>>> adj(n + 1);
    
    int u, v, w;
    // 3. 讀取 m 條邊
    for(int i = 0; i < m; ++i){ 
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    primMST(n, adj);
    return 0;
}