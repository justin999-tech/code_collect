//The tricky part of this problem is to deal with input 
//because two consecutive sets are seperated by a blank line
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 10005;
vector<pair<int,int>> adj[MAXN];
bool visited[MAXN];
int max_dist = 0;
int farthest_node = 0;

//DFS:find the farest node and its length
void dfs(int u, int current_dist){
    visited[u]=true;
    if(current_dist > max_dist){
        max_dist = current_dist;
        farthest_node = u;
    }

    for(auto& edge : adj[u]){
        int v = edge.first;
        int w = edge.second;
        if(!visited[v]) dfs(v,current_dist + w);
    }
}

//operate dfs DFS twice to find the diameter
void solve(){
    //find the starting node
    int start_node = 0;
    for(int i=1; i<MAXN; i++){
        if(!adj[i].empty()){
            start_node = i;
            break;
        }
    }

    //edge case
    if(start_node==0){
        cout<<0<<endl;
        return;
    }

    //第一遍 DFS: 找最遠點
    max_dist = 0;
    memset(visited, 0, sizeof(visited));
    dfs(start_node, 0);

    // 第二遍 DFS: 從剛才找到的最遠點 (farthest_node) 出發
    int start_node_2 = farthest_node;
    max_dist = 0;
    memset(visited, 0, sizeof(visited));
    dfs(start_node_2, 0);

    cout << max_dist << endl;

}
int main(){
    string line;
    while(getline(cin,line)){
        if(line.empty()){
            solve();
            for(int i=0; i<MAXN; i++) adj[i].clear();
            continue; //continue is for while or for loops, since an if statement only executes once by nature.
        }
        stringstream ss(line);
        //getline only comsume whole line
        //use stringstream to deal with 3 seperated data
        int u,v,w;
        ss>>u>>v>>w;
        //construct adj
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    // the next line of the last set input is EOF not blank line
    solve();
    return 0;
}

/*
memset(指標, 值, 大小)

指標 (Pointer)：也就是你要填寫的陣列名稱。

例如：visited

值 (Value)：你要填入的內容。

例如：0 (表示未訪問) 或 -1。

⚠️ 注意：這裡的「值」是針對 每個 Byte (位元組) 填寫的，不是針對每個 int 元素（這點超級重要，下面會詳解）。

大小 (Size)：你要填寫的總 Byte 數。

絕對不要只寫陣列長度（例如 100）！

一定要配合 sizeof() 使用。因為一個 int 通常佔 4 bytes，如果你只寫 100，它只會填滿前 25 個整數而已。

正確寫法：sizeof(visited)

*/