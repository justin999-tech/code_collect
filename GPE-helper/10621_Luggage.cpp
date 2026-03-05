// Uva10664
// #dp 0/1背包 #subset_sum
#include<bits/stdc++.h>
using namespace std;
void solve(){
    string line;
    getline(cin,line);
    stringstream ss(line);
    vector<int> weight;
    int item;
    while(ss>>item){ //不確定有幾個的輸入法
        weight.push_back(item);
    }
    int total=0;
    for(auto wei : weight){
        total+=wei;
    }
    if (total%2==1){
        cout<<"NO"<<endl;
        return;
    }
    int target = total/2;
    vector<bool> dp(target+1,false);
    dp[0]=1;
    for(auto wei : weight){
        for(int i=target; i>=wei; i--){ // 0/1背包一定要用減的
            //assume this item is 3kg, if we use i++, then dp[3],dp[6] become true 
            //but we just have 1 item, if i++ is Unbounded Knapsack(完全背包)
            if(dp[i-wei]){
                dp[i]=true;
            }
        }
    }
    if(dp[target]==true){
        cout<<"YES"<<endl;
        return ;
    }
    else{
        cout<<"NO"<<endl;
        return ;
    }
}
int main(){
    int t;
    cin>>t;
    string line;
    getline(cin,line); //吃掉第一個換行
    while(t--){
        solve();
    }
    return 0;
}