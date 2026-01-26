#include<bits/stdc++.h>
using namespace std;
int main(){
    int num;
    cin>>num;
    vector<int> v1(num);
    vector<vector<int>> grid(num+1,vector<int>(num+1,0));
    for(int i=0; i<num; i++){
        int element;
        cin>>element;
        v1[i]=element;
    }
    vector<int> v2(v1);
    sort(v2.begin(),v2.end());
    //用v1 v2做LCS;
    for(int i=1; i<num+1; i++){
        for(int j=1; j<num+1; j++){
            if(v1[i-1]==v2[j-1]){
                grid[i][j]=grid[i-1][j-1]+1;
            }
            else{
                grid[i][j]=max(grid[i-1][j],grid[i][j-1]);
            }
        }
    }
    cout<<grid[num][num]<<endl;
    return 0;
}