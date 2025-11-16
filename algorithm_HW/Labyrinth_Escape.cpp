//chrome-extension://efaidnbmnnnibpcajpcglclefindmkaj/https://nycu-oj.cs.nycu.edu.tw/course/problems/533/text
#include <bits/stdc++.h>
using namespace std;

bool inside_grid(int row_idx, int column_idx, int R, int C) {
    return (0 <= row_idx && row_idx < R && 0 <= column_idx && column_idx < C);
}

int escape(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<bool>> visit(n, vector<bool>(m, false));

    // 四個方向
    vector<pair<int,int>> direction = {{-1,0}, {0,1}, {1,0}, {0,-1}};

    queue<tuple<int,int,int>> q;  // (row, col, dist) dist=distance

    // 找起點 s，推進 queue
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 's') {
                q.emplace(i, j, 0);
                /*
                直接在裡面建好tuple
                等價 : 
                q.push(make_tuple(i,j,0))，這是先建好再丟進去，但效果一樣
                */
                visit[i][j] = true;
            }
        }
    }

    // BFS
    while (!q.empty()) {
        auto [r, c, d] = q.front();
        /*等價寫法
        auto cur = q.front();      // cur 的型別是 tuple<int,int,int>
        int r = get<0>(cur);       // 取第 0 個
        int c = get<1>(cur);       // 取第 1 個
        int d = get<2>(cur);       // 取第 2 個
        */
        q.pop();

        // 如果到達出口 e，d 就是最短距離
        if (grid[r][c] == 'e') {
            return d;
        }

        // 擴展四個方向
        for (auto dir : direction) {
            int nr = r + dir.first;
            int nc = c + dir.second;

            if (inside_grid(nr, nc, n, m) &&
                !visit[nr][nc] &&
                grid[nr][nc] != '#') {   // 不能是牆
                visit[nr][nc] = true;
                q.emplace(nr, nc, d + 1);
            }
        }
    }

    // 找不到 e
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num_case;
    cin >> num_case;
    while (num_case--) {
        int row, column;
        cin >> row >> column;

        vector<vector<char>> grid(row, vector<char>(column));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                cin >> grid[i][j];
            }
        }

        cout << escape(grid) << '\n';
    }
    return 0;
}
//以下是原先版本的dfs，但dfs不適合算最短路徑，因為會到處亂鑽
/*#include<bits/stdc++.h>
using namespace std;
int ans;
bool inside_grid(vector<vector<int>>& grid, int row_idx, int column_idx){
    return (0 <= row_idx&& row_idx< grid.size() && 0<=column_idx && column_idx<grid[0].size());
}

void dfs(vector<vector<int>>& grid, vecetor<pair<int,int>>& direction, 
         vector<vector<bool>>& visit, int cur_row, int cur_column, int &ans){
            ans++;
            visit[cur_row][cur_column] = true;
            for(int i=0; i<direction.size();i++){
                int adj_row = cur_row + direction[i].first;
                int adj_column = cur_column + direction[i].second;
                if( inside_grid(grid,adj_row,adj_column) && visit[adj_row][adj_column]==1){
                    dfs(grid,direction,visit,adj_row,adj_column,ans);
                }
            }
         }
int escape(vector<vector<int>>& grid){
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<bool>> visit(n,vector<int>(m,false));
    int ans=0;
    vector<pair<int,int>> direction={{-1,0},{0,1},{1,0},{0,-1}};
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]=='s'){
                dfs(grid,direction,visit,i,j,ans);
            }
        }
    }
    return ans;
}
int main(){
    int num_case;
    cin>>num_case;
    for(int i=0; i<num_case; i++){
        int row,column;
        cin>>row>>column;
        vector<vector<char>> grid(row,vector<char>(column));
        for(int j=0; j<row; j++){
            for(int k=0; k<column; k++){              
                cin>>grid[j][k];                  
            }
        }
        cout<<escape(grid)<<endl;
    }
    return 0;
}*/