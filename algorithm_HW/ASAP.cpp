#include <iostream>
#include <vector>
#include <algorithm> // for min

using namespace std;

// 1. 定義常數，確保前後一致。1e15 夠大且不會 overflow (最長路徑約 1e12)
const long long INF = 1e15; 

void Floyd_Warshell(int V, int E, vector<vector<long long>>& grid){
    for(int cur=1; cur<=V; cur++){
        for(int row=1; row<=V; row++){
            // 優化：如果起點到中繼點已經不可達，就不用試了
            if(grid[row][cur] == INF) continue;

            for(int column=1; column<=V; column++){
                if(grid[cur][column] == INF) continue;

                grid[row][column] = min(grid[row][column], grid[row][cur] + grid[cur][column]);
            }
        }
    }
}

int main(){
    // 加速輸入輸出
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E;
    if (!(cin >> V >> E)) return 0;

    // 2. 使用 INF 初始化
    vector<vector<long long>> grid(V + 1, vector<long long>(V + 1, INF));
    
    // 初始化對角線
    for(int i=1; i<=V; i++){
        grid[i][i] = 0;
    }

    for(int i=0; i<E; i++){
        int u, v;
        long long weight;
        cin >> u >> v >> weight;
        // 3. 修正多重邊問題：取最小值
        grid[u][v] = min(grid[u][v], weight);
    }

    Floyd_Warshell(V, E, grid);

    int num;
    cin >> num;
    while(num--){ // 建議用 while(num--) 寫法比較簡潔
        int a, b;
        cin >> a >> b;
        
        // 4. 判定標準要跟初始化一致
        if(grid[a][b] == INF)
            cout << "unreachable" << "\n";
        else
            cout << grid[a][b] << "\n";
    }
    return 0;
}