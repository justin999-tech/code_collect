//https://www.geeksforgeeks.org/dsa/topological-sorting-indegree-based-solution/
/*The idea is to use Kahn’s Algorithm, which applies BFS to generate a valid topological ordering.
 We first compute the in-degree of every vertex — representing how many incoming edges each vertex has. Then, all vertices with an in-degree of 0 are added to a queue, as they can appear first in the ordering.
 We repeatedly remove a vertex from the queue, add it to our result list, and reduce the in-degree of all its adjacent vertices. If any of those vertices now have an in-degree of 0, they are added to the queue.
 This process continues until the queue is empty, and the resulting order represents one valid topological sort of the graph.*/
 #include<bits/stdc++.h>
 using namespace std;
 vector<int> Kahn_algorithm(vector<vector<int>>& adjacent, vector<int>& indegree){
    queue<int> q;
    vector<int> ans;
    for(int i=0; i<adjacent.size(); i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        //處理第一個值的成員
        for(auto& adj : adjacent[q.front()]){
            indegree[adj]--;
            if(indegree[adj]==0){
                q.push(adj);
            }
        }
        ans.push_back(q.front());
        q.pop(); 
    }
    return ans;
 }
 int main(){
    int total_number,num_pair;
    //total_number : 1~n
    cin>>total_number>>num_pair;
    vector<int> indegree(total_number,0);
    vector<vector<int>> adjacent(total_number);
    for(int i=0; i<num_pair; i++){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        adjacent[a].push_back(b);
        indegree[b]++;
    }
    auto result = Kahn_algorithm(adjacent,indegree);
    for(auto& vertix : result){
        cout << vertix+1 << " ";  
    }
    cout<<endl;
    return 0;
 }
 // Queue function
  /*push：把值加到尾巴
    pop：移除頭的值
    back：回傳尾巴的值
    front：回傳頭的值
    size：回傳目前長度
    empty：回傳是否為空*/