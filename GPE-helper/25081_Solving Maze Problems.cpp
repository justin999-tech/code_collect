#include<bits/stdc++.h>
using namespace std;
vector<vector<char>> parent(10,vector<char>(10,'N'));
vector<vector<char>> visited(10,vector<char>(10,false));
void find_path(vector<vector<char>>& grid, int x, int y){
    if(grid[x][y]=='S'){
        grid[x][y]='+';
        return;
    }
    grid[x][y]='+';
    if(parent[x][y]=='U'){
        find_path(grid,x-1,y);
    }
    else if(parent[x][y]=='D'){
        find_path(grid,x+1,y);
    }
    else if(parent[x][y]=='R'){
        find_path(grid,x,y+1);
    }
    else{
        find_path(grid,x,y-1);
    }
}
void dfs(vector<vector<char>>& grid, int x, int y){ //要處理路徑回朔
    visited[x][y]=true;
    vector<pair<int,int>> dir={{-1,0},{0,1},{1,0},{0,-1}}; //上、右、下、左
    if(grid[x][y]=='G'){
        grid[x][y]='+';
        find_path(grid,x,y);
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                cout<<grid[i][j];
            }
            cout<<endl;
        }
        exit(0);
    }
    for(int i=0; i<4; i++){
        int cur_x = x+dir[i].first;
        int cur_y = y+dir[i].second;
        if(cur_x<0 || cur_x>=10 || cur_y<0 || cur_y>=10) continue;
        if(grid[cur_x][cur_y]=='#') continue;
        if(grid[cur_x][cur_y]!='#' && visited[cur_x][cur_y]==false){
            if(i==0){
                parent[cur_x][cur_y]='D';
            }
            else if(i==1){
                parent[cur_x][cur_y]='L';
            }
            else if(i==2){
                parent[cur_x][cur_y]='U';
            }
            else{ //i==3
                parent[cur_x][cur_y]='R';
            }
            dfs(grid,cur_x,cur_y);
        }
    }
}
int main(){
    vector<vector<char>> grid(10,vector<char>(10));
    char ch;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cin>>ch;
            grid[i][j]=ch;
        }
    }
    //dfs from s
    bool find = false;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if(grid[i][j]=='S'){
                dfs(grid,i,j);
                find =true;
                break;
            }
        }
        if(find==true) break;
    }
    return 0;
}