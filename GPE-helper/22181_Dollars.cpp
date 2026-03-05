#include<bits/stdc++.h>
using namespace std;
//轉移式:dp[i]=dp[i]+dp[i-coin_i]
//exteranl for loop : run each coin
//internal for loop : from coin_i to 30000(must run increasingly)
vector<long long> dp(300001,0);
vector<int> coins={10000,5000,2000,1000,500,200,100,50,20,10,5};
void precalculate(){
    //先算好所有dp
    dp[0]=1;
    for(int coin : coins){
        for(int i=coin; i<=30000; i++){
            dp[i]=dp[i]+dp[i-coin];
        }
    }

}
long long solve(int i){
    return dp[i];
}
int main(){
    precalculate();
    float ask;
    while(cin>>ask && ask!=0.00){
        int tmp=round(ask*100); //一定要加round因為假如是17.25，電腦裡面有可能是存成17.249999，強行轉乘int電腦是無條件捨去
        long long res=solve(tmp);
        printf("%6.2f",ask);//總共6位小數點後面占2位
        printf("%17lld",res);
        cout<<endl;
    }
    return 0;
}