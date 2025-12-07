//https://www.geeksforgeeks.org/dsa/floyd-warshall-algorithm-dp-16/
//This algorithm works for both the directed and undirected weighted graphs 
//and can handle graphs with both positive and negative weight edges.
//‼️Note: It does not work for the graphs with negative cycles 
//(where the sum of the edges in a cycle is negative).
//📍using optimal substructure property(DP)
//📍better for Dense Graphs and not for Sparse Graphs because of O(V^3)
//📍let each node as imtermedium.
#include<bits/stdc++.h>
using namespace std;
const int INF = 1e8;
void Floyd_Warshall(vector<vector<long long>>& dp){
    int n=dp.size();
    for(int cur=0; cur<n; cur++){
        for(int row=0; row<n; row++){
            if(row==cur)
                continue;
            for(int column=0; column<n; column++){
                if(column==cur)
                    continue;
                dp[row][column]=min(dp[row][column],dp[row][cur]+dp[cur][column]);
            }
        }
    }
}
int main (){
    int V;
    cin>>V; // 0~V-1 nodes
    vector<vector<long long>> grid(V,vector<long long>(V));
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            long long  edge;
            cin>>edge;
            grid[i][j]=edge;
        }
    }
    Floyd_Warshall(grid);
    for(auto& row : grid){
        for(auto& result : row){
            if(result==INF){
                cout<<"INF"<<" ";
                continue;
            }
            cout << setw(2)<<result << "  ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}