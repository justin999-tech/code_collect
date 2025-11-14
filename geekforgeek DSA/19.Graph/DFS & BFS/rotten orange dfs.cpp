#include<bits/stdc++.h>
using namespace std;
bool is_safe(int x, int y, int n, int m){
    return (0<=x && x<n && 0<=y && y<m);
}
void dfs(vector<vector<int>>& mat, int i, int j, int time){
    int n=mat.size();
    int m=mat[0].size();
    //update the minimum time
    mat[i][j]=time;
    vector<vector<int>> directions={{1,0},{-1,0},{0,1},{0,-1}};
    //change 4-direction cell
    for(auto dir : directions){
        int x=i+dir[0];
        int y=j+dir[1];
        if(is_safe(x,y,n,m)&&(mat[x][y]==1||mat[x][y]>(time+1))){
            dfs(mat,x,y,time+1);
        }
    }

}
int orange_rot(vector<vector<int>>& mat){
    int n=mat.size();
    int m=mat[0].size();
    int result_time = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j]==2){
                //the reason that start from 2 is that 
                //it must be different from the default cases 1 and 0
                dfs(mat,i,j,2);
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j]==1){
                return -1;
            }
            result_time=max(result_time,mat[i][j]-2);
        }
    }
    return result_time;
}
int main(){
    int row_num,column_num;
    cin >> row_num >> column_num;
    vector<vector<int>> mat(row_num, vector<int>(column_num, 0));
    for(int i=0; i<row_num; i++){
        for(int j=0; j<column_num; j++){
            cin>>mat[i][j];
        }
    }
    cout<<orange_rot(mat)<<endl;
    return 0;
}