//區間dp
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> memo(55,vector<int>(55,-1));

int solve(int left, int right, vector<int>& v){
    if(left+1==right) return 0;
    if(memo[left][right]!=-1){
        return memo[left][right];
    }
    int min=INT_MAX;
    for(int i=left+1; i<=right-1; i++){ // i is index
        int tmp = solve(left,i,v) + solve(i,right,v) + (v[right]-v[left]) ;
        if(tmp<min){
            min = tmp;
        }
    }
    memo[left][right]=min;
    return min;
}
int main(){
    int length;
    while(cin>>length && length!=0){
        //reset memo
        for(int i=0; i<55; i++){
            for(int j=0; j<=55; j++){
                memo[i][j]=-1;
            }
        }
        int num;
        cin>>num;
        vector<int> v;
        v.push_back(0);
        for(int i=0; i<num; i++){
            int tmp;
            cin>>tmp;
            v.push_back(tmp);
        }
        v.push_back(length);
        sort(v.begin(),v.end());
        int min=INT_MAX;
        min=solve(0,v.size()-1,v);
        cout<<"The minimum cutting is "<<min<<"."<<endl;
    }
    return 0;
}