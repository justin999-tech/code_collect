// Uva 10912
// #dp
//觀察到0<L<=26 0<S<=351
//dp[i][j][k]表示用前i個字母組合成的L=j,S=k的組合數
//對於新加入的i，轉移式:dp[i][j][k]=dp[i-1][j][k](不新增)+dp[i-1][j-1][k-i]
//dp全部都先算出來=26*26*351次運算再查表O(1)
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<vector<int>>> dp(27,vector<vector<int>>(27,vector<int>(352,0)));
    dp[1][1][1]=1; //a
    dp[2][1][1]=1; //a
    dp[2][1][2]=1; //b
    dp[2][2][3]=1; //ab
    for(int i=1; i<=26; i++){
        dp[i][0][0]=1;
    }
    for(int i=3; i<=26; i++){
        for(int j=1; j<=26; j++){
            for(int k=1; k<=351; k++){
                if(k-i>=0){
                    dp[i][j][k]=dp[i-1][j][k]+dp[i-1][j-1][k-i];
                }
                else{
                    dp[i][j][k]=dp[i-1][j][k];
                }
            }
        }
    }
    int L,S;
    int count = 1;
    while(cin>>L>>S && L!=0){
        if(L<=26 && S<=351){
            cout<<"Case "<<count<<": "<<dp[26][L][S]<<endl;
            count++;
        }
        else{
            cout<<"Case "<<count<<": "<<0<<endl;
            count++;
        }
    }
    return 0;
}