//https://www.geeksforgeeks.org/dsa/topological-sort-using-dfs/
//code is for algorithm homework
//notice that the answer may not unique, so it's normal that cph may show "fail"
#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int>& visit, vector<vector<int>>& adjacent,stack<int>& st, int i){
    if(visit[i]==0)
        visit[i]=1;
    for(auto adj : adjacent[i]){
        if(visit[adj] == 0){
            dfs(visit,adjacent,st,adj);
        }
    }
    //在自己的所有鄰居都處理完後才把自己放進去
    st.push(i);
}
vector<int> topological_sort(vector<vector<int>>& adjacent){
    int n=adjacent.size();
    vector<int> visit(n,0);
    stack<int> st;
    for(int i=0; i<n; i++){
        if(visit[i]==0)
            dfs(visit,adjacent,st,i);
    }
    vector<int> result;
    for(int i=0; i<n; i++){
        result.push_back(st.top());
        st.pop();
    }
    return result;
}
void push_into_adjacent(vector<vector<int>>& adjacent, int a, int b){
    //because of DAG(directed acycle graph), we should only push_back into vector one time
    adjacent[a].push_back(b);
}
int main(){
    int num_case;
    cin>>num_case;
    for(int i=0; i<num_case; i++){
        int total_num, num_edge;
        cin>>total_num>>num_edge;
        vector<vector<int>> adjacent(total_num);
        for(int j=0; j<num_edge; j++){
            int a,b;
            cin>>a>>b;
            //convert to 0-based
            a--;
            b--;
            push_into_adjacent(adjacent,a,b);
        }
        for(auto& vertix : topological_sort(adjacent)){
            cout<<vertix+1<<" ";
        }
        cout<<endl;
    }
    return 0;
}