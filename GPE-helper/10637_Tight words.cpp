//Uva 10081
//#dp
#include<bits/stdc++.h>
using namespace std;
int main(){
    int k,n;
    while(cin>>k>>n){
        //數字可以重複使用
        //edge case
        if(k==0){
            if(n==0){
                cout<<"0.00000"<<endl;
                continue;
            }
            if(n>=1){
                cout<<"100.00000"<<endl;
                continue;
            }
        }
        if(k==1){
            if(n==0){
                cout<<"0.00000"<<endl;
                continue;
            }
            if(n>=1){
                cout<<"100.00000"<<endl;
                continue;
            }
        }
        vector<vector<double>> dp(n+1,vector<double>(k+1,0.0));
        for(int i=0; i<=k; i++){
            dp[0][i]=0.0;
        }
        for(int i=0; i<=k; i++){
            dp[1][i]=1.0/(double)(k+1);
        }
        for(int i=2; i<=n; i++){ 
            for(int j=0; j<=k; j++){ 
                if(j==0){
                    dp[i][j]=(dp[i-1][j]+dp[i-1][j+1])/(double)(k+1);
                }
                else if(j==k){
                    dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])/(double)(k+1);
                }
                else{
                    dp[i][j]=(dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1])/(double)(k+1);
                }
            }
        }
        //ask = dp[n](Marginal Probability)
        double ask=0;
        for(int i=0; i<=k; i++){
            ask+=dp[n][i];
        }
        ask*=100;
        printf("%.5f\n",ask);
        //cout<<fixed<<setprecision(5)<<ask<<endl;
    }
    return 0;
}