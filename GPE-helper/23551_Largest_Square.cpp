#include<bits/stdc++.h>
using namespace std;
bool check_same(int a, int b, int gap, vector<vector<char>>& grid){
    for(int i=a-gap; i<=a+gap; i++){
        for(int j=b-gap; j<=b+gap; j++){
            if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()){
                return false;
            }
            if(grid[i][j]!=grid[a][b]){
                return false;
            }
        }
    }
    return true;
}
int main(){
    int cases;
    cin>>cases;
    while(cases--){
        int m,n,num_center;
        cin>>m>>n>>num_center;
        cout<<m<<" "<<n<<" "<<num_center<<endl;
        vector<vector<char>> grid(m,vector<char>(n));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                char entry;
                cin>>entry;
                grid[i][j] = entry;
            }
        }
        while(num_center--){
            int a,b;
            cin>>a>>b;
            for(int i=0; i<105; i++){ //grid:(2i+1)*(2i+1)
                if(!check_same(a,b,i,grid)){
                    cout<<2*i-1<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}