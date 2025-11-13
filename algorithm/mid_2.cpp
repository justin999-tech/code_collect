#include<bits/stdc++.h>
using namespace std;
int main(){
    int num_case;
    cin>>num_case;
    for(int i=0; i<num_case; i++){
        int num_coin;
        cin>>num_coin;
        vector<int> coin(10001); //考試少了（1001)
        for(int j=0; j<num_coin;j++){
            cin>>coin[j];
        }
        vector<long long int> dp;
        int target;
        cin>>target;
        int min;
        dp.push_back(0);
        if(target==0){
            cout<<0<<endl;
        }
        else if(num_coin==1){
            if(target%coin[0]!=0)
                cout<<-1<<endl;
            else if(target%coin[0]==0){
                int ans=target/coin[0];
                cout<<ans<<endl;
            }
        }
        else{
            for(int cur=1; cur<=target; cur++){
                for(int j=0; j<num_coin; j++){
                    if(cur-coin[j]>=0)
                        min=dp[cur-coin[j]];
                }
            dp.push_back(min+1);
            }
            cout<<dp[target]<<endl;
        }
    }
    return 0;
}