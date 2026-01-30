//Uva 10336
//#flood fill
#include<bits/stdc++.h>
using namespace std;
void dfs(int i, int j, vector<string>& grid, vector<vector<bool>>& visited){
    vector<pair<int,int>> dir={{-1,0},{0,1},{1,0},{0,-1}};
    visited[i][j]=true;
    for(int k=0; k<=3; k++){
        int next_i=i+dir[k].first;
        int next_j=j+dir[k].second;
        if(next_i>=0 && next_i<grid.size() && next_j>=0 && next_j<grid[0].size() && grid[next_i][next_j]==grid[i][j] && visited[next_i][next_j]==false){
            dfs(next_i,next_j,grid,visited);
        }
    }
}
bool cmp(pair<char,int>& a, pair<char,int>& b){ //true的話a排前面
        //先比number後比language
        if(a.second!=b.second){
            return a.second>b.second;
        }
        if(a.first!=b.first){
            return a.first<b.first;
        }
    }
int main(){
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++){
        int h,w;
        cin>>h>>w;
        vector<string> grid(h);
        for(int i=0; i<h; i++){
            string line;
            cin>>line;
            grid[i]=line;
        }
        cout<<"World #"<<i+1<<endl;
        vector<vector<bool>> visited(h,vector<bool>(w,false));
        //step1 對每個entry做dfs
        //step2 先把每個字母對應的次數存進times
        //step3 再把map當作pair存入vector因為我們要用sort
        //step4 按照順序print出來
        map<char,int> times; 
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(visited[i][j]==false){
                    times[grid[i][j]]++;
                    dfs(i,j,grid,visited);
                }
            }
        }
        vector<pair<char,int>> v;
        for(auto const& [language, number] : times){
            v.push_back({language,number});
        }
        sort(v.begin(),v.end(),cmp);
        for(auto const& [lang,ans] : v){
            cout<<lang<<": "<<ans<<endl;
        }
    }
    return 0;
}