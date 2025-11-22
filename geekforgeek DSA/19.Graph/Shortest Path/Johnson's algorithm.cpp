// https://www.geeksforgeeks.org/dsa/johnsons-algorithm/
//‼️輸入用0當作不存在的路徑(後面會處理)
// Q:都要做一次完整的 Bellman(special source as source) + dijkstra，為甚麼不直接用bellman就好了
// A:bellman can only to find the a specific source to the others nodes,
// but johnson can find every pairs of shortest path
// step:use bellman to determine h[i], edge(i,j) -> edge(i,j) + h[i] - h[j], then dijkstra
// 📍because with a new special source, h[j] <= h[i] + edge(i,j), 
// which is euqal edge(i,j) + h[i] - h[j] => 0, suceesfully change the edge to above 0 without changing the shortest path
/*
time complexity : (find every pair)(以下不考慮dijkstra因為不能處理negative-weight)
bellman-ford = V*O(EV)=O(E*V²)
johnson =
    one time bellman-ford = O(EV)
+)  V times dijlstra      = V*O(ElogV) = O(EVlogV)
---------------------------------------------------------
    johnson               = O(EVlogV)

normal condition -> E=cV(i.e頂點數跟邊數同等級) -> johnson is better than bellman-ford
if dense graph->E ≈ V²(i.e for every vertix there are many edges atteched to it)
Floyd-Warshall is O(V³) which is better than bellman-ford : O(V⁴) and johnson : O(V³logV) 
*/ 
#include<bits/stdc++.h>
using namespace std;
const long long INF = (long long)1e15;
// 在重加權後的圖上跑 Dijkstra
void dijkstra_reweight(const vector<vector<pair<int,long long>>>& adj,
int source, vector<long long>& dist){
    int n=adj.size();
    dist.assign(n,INF);
    dist[source]=0;

    //construct min-heap to get min-unexplored node
    using P = pair<long long, int>; //{dist,node}
    priority_queue<P,vector<P>,greater<P>> pq;
    pq.push({0,source});

    while(!pq.empty()){
        auto [d,u] = pq.top();
        pq.pop();
        if(d!=dist[u])
            continue;
        
        for(auto[v,w] : adj[u]){
            if(d + w < dist[v]){
                dist[v] = d + w;
                pq.push({dist[v],v});
            }
        }
    }
}
// Bellman-Ford from super-source
// origin: 原始 adjacency matrix，0 = 沒有邊，其他值 = 權重
// h: 會被填成 h[0..n-1] = super-source 到每個點的最短距離
// 回傳 false 代表有 negative cycle
bool bellman_ford_with_super_source(const vector<vector<int>>& origin,
vector<long long>& h){
    int n=origin.size();
    int V=n+1;
    int super=n;

    h.assign(V,INF);
    h[super]=0;

    struct Edge{
        int u,v;
        int w;
    };

    vector<Edge> edges;

    // super-source -> 每個節點，權重 0
    for(int i=0; i<n; i++){
        edges.push_back({super,i,0});
    }
    //original graph
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (origin[i][j] != 0) {  // 0 = 沒有邊
                edges.push_back({i, j, origin[i][j]});
            }
        }
    }

    //Bellman-Ford : 做 V-1 輪 relax
    for(int iter=0; iter < V-1; iter++){
        bool update=false;
        for(auto& e : edges){
            if(h[e.u]==INF)
                continue;
            if(h[e.u] + e.w < h[e.v]){
                h[e.v] = h[e.u] + e.w;
                update = true;
            }
        }
        if(!update)
            break; //提早結束
    }

    //多跑一輪檢查是否有 negative cycle
    for(auto& e : edges){
        if(h[e.u]==INF)
            continue;
        if(h[e.u] + e.w < h[e.v])
            return false; //there is negative cycle
    }

    //刪掉 super-source 那一格，只留下 0..n-1
    h.pop_back();
    return true;
}
// Johnson's Algorithm
// origin: n x n adjacency matrix
// shortest: 輸出 n x n 矩陣，shortest[u][v] = u 到 v 的最短距離
// h_out: 輸出每個 h[i]
bool johnson(const vector<vector<int>>& origin,
vector<vector<long long>>& shortest,vector<long long>& h_out){
    int n = origin.size();
    if(n==0)
        return true;
    
    // step 1 : Bellman + super-souce
    vector<long long> h;
    if(!bellman_ford_with_super_source(origin,h)){
        //there is negative cycle
        return false; 
    }
    h_out = h;// 存起來給主程式印

    //step 2 : Construct a reweighted adjacency list
    vector<vector<pair<int,long long>>> adj(n);
    for(int u=0; u<n; u++){
        for(int v=0; v<n; v++){
            if(origin[u][v]!=0){
                long long w = origin[u][v];
                long long w_prime = w + h[u] - h[v]; //w'(u,v)
                adj[u].push_back({v,w_prime});
            }
        }
    }

    //step 3 : Treat each node as the source and 
    //run Dijkstra on the reweighted graph.
    shortest.assign(n,vector<long long>(n,INF));
    vector<long long> dist_reweight;

    for(int s=0; s<n; s++){
        dijkstra_reweight(adj,s,dist_reweight);
        for(int v=0; v<n; v++){
            if(dist_reweight[v]==INF)
                shortest[s][v]=INF;
            else
                //還原成原始圖的最短路徑長度：
                shortest[s][v] = dist_reweight[v] - h[s] + h[v];
        }
    }

    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    //vertices are marked 0~n-1
    cin>>n;
    // 0=沒有邊，其餘為權重
    vector<vector<int>> origin(n,vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>origin[i][j];
        }
    }

   vector<vector<long long>> shortest;
   vector<long long> h;

   if(!johnson(origin,shortest,h)){
        cout<<"Graph contains at least one negative cycle !\n";
        return 0;//直接結束整個程式
   }
   
   //印出所有h
   cout<<"------------------------------------"<<endl;
   cout<<"h[i](potential from super-source) :\n";
   for(int i=0; i<(int)h.size(); i++){
        cout<<"h["<<i<<"] = "<<h[i]<<endl;
    }
   cout<<endl;
   cout<<"All-pairs shortest path matrix :\n";
   for(int i=0; i<shortest.size(); i++){
        for(int j=0; j<shortest.size(); j++){
            if(shortest[i][j]==INF)
                cout<<"INF"<<" ";
            else    
                cout<<setw(3)<<shortest[i][j]<<" ";
        }
        cout<<"\n";

   }
    return 0;
}
