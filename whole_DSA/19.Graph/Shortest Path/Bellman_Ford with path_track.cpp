//this Bellman Ford algorithm contain path track funnction !
//this code deal with directed-with-negative-weight graph 
//Mainly use the "relaxing thinking"
#include<bits/stdc++.h>
using namespace std;
const int INF = 1e8;
vector<int> getpath(int src, int dest, vector<int> dist, vector<int> parent){
    if (dest < 0 || dest >= (int)dist.size()) return {};
    if (dist[dest] == INF) return {};

    vector<int> path;
    //會跑到getpath就是沒有negative cycle
    int cur = dest;
    while (1) {
        path.push_back(cur);
        if (cur == src) break;
        cur = parent[cur];
    }
    if (path.back() != src) return {}; 
    //無法到達(ex.this node only has facing-outward arrow 
    //        ex.this node is isolated from other node-net)
    reverse(path.begin(), path.end());
    return path;
}
pair<vector<int>,vector<int>> Bellman_Ford (int V, int src, vector<vector<int>>& edges){
    //每一個node的parent只有有一個，並且會隨者不同的時間更新
    vector<int> parent(V,-1);
    vector<int> distance(V,INF);
    distance[src]=0;
    vector<vector<int>> adjacents(V);
    for(auto& edge : edges){
        adjacents[edge[0]].push_back(edge[1]);
    }
    
    for(int i=0; i<V; i++){
        //each sweep -> relaxing every edge
         bool update = false;
        for(auto& edge : edges){        
            auto[u,v,wt] = tuple(edge[0],edge[1],edge[2]);
            if(distance[u]!=INF && distance[u] + wt < distance[v]){
                if(i==V-1){
                    return {vector<int> {-1}, vector<int> {}};
                }
                distance[v]=distance[u] + wt;
                parent[v]=u;
                update=true;
            }
        }
        if(update==false)
              break; // 直接結束for_loop
    }
     return {distance,parent};
}
int main(){
    int src,V,u,v,weight;
    //V nodes maked 0 ~ V-1;
    cin>>V>>src;
    vector<vector<int>> edges;
    while(cin >> u >> v >> weight){
        edges.push_back({u,v,weight});
    }
    auto [dist,parent] = Bellman_Ford(V,src,edges);
    if(dist.size()==1 && dist[0]==-1){
        cout<<"The graph has a negative cycle !"<<endl;
        return 0; //直接結束所有程式
        }
    cout << "distance from source is : "<<endl;
    for(int i=0; i<V; i++){
        cout<<i<<" (as destination) is ";
        if(dist[i]==INF)
            cout<<"INF"<<endl;
        else
            cout<<dist[i]<<endl;
    }
    cout<<"---------------------------------------"<<endl;
    cout<<"Path from source is : "<<endl;
    for(int destination = 0 ; destination < V ; destination++){
        vector<int> path = getpath(src,destination,dist,parent);
        if(path.empty())
            cout<<"No path to "<<destination<<" !"<<endl;
        else{
            cout << "path to " << destination << " : ";
            for (int v=0; v<path.size(); v++) {
                if(v!=path.size()-1)
                    cout << path[v] << " → ";
                else
                    cout<<path[v];
            }
            cout << "\n";
        }
            
    }
    return 0;
}