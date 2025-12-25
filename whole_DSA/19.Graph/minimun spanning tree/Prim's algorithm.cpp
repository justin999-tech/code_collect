#include<bits/stdc++.h>
using namespace std;
struct ResultEdge{
    int u,v,weight;
};
void primMST(int n, const vector<vector<pair<int,int>>>& adj){
    // Min-Priority Queue: <權重, 目前點, 來源點>
    // 使用 greater 讓它變成 Min-Heap (權重小的在上面)
    priority_queue< tuple<int,int,int> , vector<tuple<int,int,int>> , greater<tuple<int,int,int>> > pq;
    vector<bool> visited(n,false);
    vector<ResultEdge> res_edges;
    long long sum=0;
    int nodes_included = 0;
    // 從頂點 0 開始：權重 0, 目前點 0, 來源點 -1 (起始點無來源)
    pq.push({0,0,-1});
    while(!pq.empty()){
        auto[weight,curr,parent]=pq.top();
        pq.pop();

        if(visited[curr])
            continue;

        visited[curr]=true;
        nodes_included++;
        sum+=weight;

        if(parent!=-1){
            res_edges.push_back({parent,curr,weight});
        }

        for(const auto& neighbor : adj[curr]){
            int next_node = neighbor.first;
            int to_neighbor_weight = neighbor.second;

            if(!visited[next_node]){
                pq.push({to_neighbor_weight,next_node,curr});
            }
        }
    }

    if(nodes_included==n){
        cout<<"Selected Edges (u, v, weight):"<<endl;
        for(const auto& edge : res_edges)
            cout<<edge.u<<" "<<edge.v<<" "<<edge.weight<<endl;
        cout<<"Total length: "<<sum<<endl;
    }

    else{
        cout<<"The graph is not connected."<<endl;
    }

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if(!(cin>>n))
        return 0;
    //pair(neighborhood,weight)
    vector<vector<pair<int,int>>> adj(n);
    int u,v,w;
    while(cin>>u>>v>>w){ //不錯的處理方法
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    primMST(n,adj);
    return 0;
}