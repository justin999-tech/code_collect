#include <bits/stdc++.h>
using namespace std;
vector<char> getpath(vector<vector<char>>& grid, vector<vector<char>>& parent, int cur_i, int cur_j,vector<char>& path){
    
    if(parent[cur_i][cur_j]=='S') 
        return path;
    else if(parent[cur_i][cur_j]!='S')
        path.push_back(parent[cur_i][cur_j]);
    switch(parent[cur_i][cur_j]){
        case 'L':
            getpath(grid,parent,cur_i,cur_j+1,path);
            break;
        case 'R':
            getpath(grid,parent,cur_i,cur_j-1,path);
            break;
        case 'U':
            getpath(grid,parent,cur_i+1,cur_j,path);
            break;
        case 'D':
            getpath(grid,parent,cur_i-1,cur_j,path);
            break;
    }
    return path;
}

bool inside_grid(int row_idx, int column_idx, int R, int C) {
    return (0 <= row_idx && row_idx < R && 0 <= column_idx && column_idx < C);
}

int escape(vector<vector<char>>& grid,vector<vector<char>>& parent) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<bool>> visit(n, vector<bool>(m, false));

    // 四個方向
    //注意座標原點在左上角
    vector<pair<int,int>> direction = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    vector<char> dir={'U','R','D','L'};

    queue<tuple<int,int,int>> q;  // (row, col, dist) dist=distance

    // 找起點 s，推進 queue
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'S') {
                q.push(make_tuple(i,j,0));
                visit[i][j] = true;
                parent[i][j]='S';
            }
        }
    }

    // BFS
    while (!q.empty()) {
        auto [r, c, d] = q.front();
        q.pop();

        // 如果到達出口 e，d 就是最短距離
        if (grid[r][c] == 'E') {
            return d;
        }

        // 擴展四個方向
        for (int i=0; i<=3 ; i++) {
            int nr = r + direction[i].first;
            int nc = c + direction[i].second;

            if (inside_grid(nr, nc, n, m) &&
                !visit[nr][nc] &&
                grid[nr][nc] != '#') {   // 不能是牆
                visit[nr][nc] = true;
                q.push(make_tuple(nr, nc, d + 1));
                parent[nr][nc]=dir[i];
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
        vector<vector<char>> parent(row,vector<char> (column,'O'));
        vector<vector<char>> grid(row, vector<char>(column));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                cin >> grid[i][j];
            }
        }
        int dist = escape(grid,parent);
        cout << dist << '\n';
        if (dist == -1) continue; // 如果找不到路徑，印出 -1

        //從'E'回推路徑
        for(int i=0; i<row; i++){
            for(int j=0; j<column; j++){
                if(grid[i][j]=='E'){
                    vector<char> path;
                    getpath(grid,parent,i,j,path);
                    for(int k=path.size()-1; k>=0; k-- ){
                        cout<<path[k];
                    }
                    cout<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}