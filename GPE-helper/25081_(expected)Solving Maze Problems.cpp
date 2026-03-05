#include<bits/stdc++.h>
using namespace std;
//一般說不用visted會造成無窮迴圈，但這邊用+代替visited
// 定義方向：上、下、左、右
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
bool found = false;

void dfs(vector<vector<char>>& grid, int x, int y) {
    if (x < 0 || x >= 10 || y < 0 || y >= 10 || grid[x][y] == '#' || grid[x][y] == '+' || found) {
        return;
    }

    if (grid[x][y] == 'G') {
        grid[x][y]='+';
        found = true;
        // 印出結果
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) cout << grid[i][j];
            cout << endl;
        }
        return;
    }

    char original = grid[x][y];
    grid[x][y] = '+'; // 標記路徑

    for (int i = 0; i < 4; i++) {
        dfs(grid, x + dx[i], y + dy[i]);
    }

    if (!found && grid[x][y] != 'S') {
        grid[x][y] = original; // 回溯：如果這條路不通，把標記拿掉
    }
}

int main() {
    vector<vector<char>> grid(10, vector<char>(10));
    int startX, startY;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') {
                startX = i; startY = j;
            }
        }
    }

    dfs(grid, startX, startY);
    return 0;
}