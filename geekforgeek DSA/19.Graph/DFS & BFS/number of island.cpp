#include<bits/stdc++.h>
using namespace std;
bool valid(int m, int n,vector<vector<char>>& island){
    return (0<=m && m<island.size() && 0<=n && n<island[0].size());
}
void dfs(int cur_row, int cur_column,vector<int>& direction_row, vector<int>& direction_column, vector<vector<bool>>& visit, vector<vector<char>>& island){
    visit[cur_row][cur_column]=true;
    for(int i=0; i<direction_row.size(); i++){
        int m=cur_row+direction_row[i];
        int n=cur_column+direction_column[i];
        if(valid(m,n,island) && !visit[m][n] && island[m][n]=='L'){
            dfs(m,n,direction_row,direction_column,visit,island);
        }
    }
}
int islandcount(int row, int column, vector<vector<char>>& island){
    int count = 0;
    vector<vector<bool>> visit(row,(vector<bool>(column,false))) ;
    vector<int> direction_row={-1,-1,-1,0,0,1,1,1};
    vector<int> direction_column={-1,0,1,-1,1,-1,0,1};
    //traverse the island
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            if(island[i][j]=='L' && !visit[i][j]){
                dfs(i,j,direction_row,direction_column,visit,island);
                count++;
            }
        }
    }
    return count;
}

int main(){
    int row;
    int column;
    cin>>row;
    cin>>column;
    vector<vector<char>> island(row,vector<char>(column,'N'));
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            cin>>island[i][j];
        }
    }
    cout<<islandcount(row,column,island)<<endl;
    return 0;
}