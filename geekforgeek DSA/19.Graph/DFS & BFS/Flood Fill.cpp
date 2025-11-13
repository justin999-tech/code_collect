#include<bits/stdc++.h>
using namespace std;
bool inside_grid(int n,int m, vector<vector<int>> grid){
    return (0<=n && n<grid.size() && 0<=m && m<grid[0].size());
}
void dfs(vector<vector<int>>& grid, int cur_row, int cur_column, int oldcolor, int newcolor){
    grid[cur_row][cur_column]=newcolor;
    // 注意每個pair要用大括號而非小括號
    vector<pair<int,int>> direction= {{-1,0},{0,1},{1,0},{0,-1}};
    for(int i=0; i<direction.size();i++){
        int m=cur_column + direction[i].first;
        int n=cur_row + direction[i].second;
        if( inside_grid(n,m,grid) && grid[n][m]==oldcolor ){
            dfs(grid,n,m,oldcolor,newcolor);
        }
    }
}

vector<vector<int>> flood_fill(vector<vector<int>>& grid,int sr,int sc,int newcolor){
    if(grid[sr][sc]==newcolor)
        return grid;
    int oldcolor=grid[sr][sc];
    dfs(grid,sr,sc,oldcolor,newcolor);
    return grid;
}
int main(){
   // row * column
   // grid[row][column]
   // sr sc ->source row & source column
   // newcolor
   int row,column,sr,sc,newcolor;
   cin>>row>>column;
   vector<vector<int>> grid(row,vector<int>(column,0));
   for(int i=0; i<row; i++){
    for(int j=0; j<column; j++){
        cin>>grid[i][j];
    }
   }
   cin>>sr>>sc>>newcolor;
   vector<vector<int>> result =flood_fill(grid,sr,sc,newcolor);
   for(auto& row:result){
    for(auto& pixel:row){
        cout<<pixel<<" ";
    }
    cout<<endl;
   }
   cout<<endl;
    return 0;
}
