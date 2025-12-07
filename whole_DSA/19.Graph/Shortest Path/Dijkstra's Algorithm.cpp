//Dijkstra’s Algorithm using Min Heap - O(E*logV) Time and O(V) Space
//https://www.geeksforgeeks.org/dsa/dijkstras-shortest-path-algorithm-greedy-algo-7/
//因為每次都要取最小的，所以用min-heap可以大幅降低難度
#include<bits/stdc++.h>
using namespace std;
vector<vector<vector<int>>> construct_adjacent(int &V, vector<vector<int>>& edges){
    //each node have a list of {v,weight}
    vector<vector<vector<int>>> adj(V); 
    for(auto& edge : edges){
        adj[edge[0]].push_back({edge[1],edge[2]});
        adj[edge[1]].push_back({edge[0],edge[2]});
    }
    return adj;
}
vector<int> dijkstra(int &V, int &src, vector<vector<int>>& edges){
    vector<int> ans(V) ;
    auto adj = construct_adjacent(V,edges);
    //用來找尋下一個最小的 unexplored node
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
    vector<int> min_distance (V,INT_MAX);
    //{dist[i],ith node}
    pq.push({0,src});
    min_distance[src]=0;
    while(!pq.empty()){
        for(auto& specific_adj : adj[pq.top()[1]]){
            //assume that now pq.top()=i,
            //then min-distance of i is the current value 
            ans[pq.top()[1]] = min_distance[pq.top()[1]];
            int finish_node = specific_adj[0];
            int weight      = specific_adj[1];
            //不能所有鄰居都放進去，要有真的變短才要丟進pq
            if(min_distance[finish_node] > min_distance[pq.top()[1]] + weight){
             min_distance[finish_node] = min_distance[pq.top()[1]] + weight;
            //找完的鄰居記得要放進 pq，且已經算完的不 push (●'◡'●)
            pq.push({min_distance[finish_node],finish_node});}
        }
        pq.pop();
    }
    return ans;
}
int main (){
    //有V個node(0~V-1)
    int V,src;
    cin>>V>>src;
    //要特別處理輸入因為不知道有幾行，但每行固定有3個數字
    vector<vector<int>> edges;
    int u, v, weight;
    while(cin >> u >> v >> weight){
        edges.push_back({u,v,weight});
    }
    vector<int> result = dijkstra (V,src,edges);
    for(auto& dist : result){
        cout<<dist<<" ";
    }
    cout<<endl;
    return 0;
}