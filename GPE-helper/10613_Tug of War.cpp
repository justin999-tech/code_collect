//Uva 10032
// #0/1 bag dp #note
#include<bits/stdc++.h>
using namespace std;
int main(){
    int cases;
    cin>>cases;
    string dummy;
    getline(cin,dummy); //eat \n
    getline(cin,dummy); //eat blank line
    int n;
    while(cases--){
        cin>>n;
        vector<int> weight;
        pair<int,int> ans;
        for(int i=1; i<=n; i++){
            int tmp;
            cin>>tmp;
            weight.push_back(tmp);
        }
        int half_people = weight.size()/2;
        int total_weight=0,half_weight=0;
        for(int i=0; i<weight.size(); i++){
            total_weight+=weight[i];
        }
        half_weight=total_weight/2;
        vector<bitset<101>> dp(45001,0); //總重量最多45000kg
        dp[0]=1;
        for(int i=0; i<weight.size(); i++){
            for(int basis=45000; basis>=0; basis--){ //一定要由大到小traverse
                if(dp[basis].any()){
                    dp[basis+weight[i]]|=(dp[basis]<<1);
                }
            }
        }
        //from half_weight -> 0 去看有沒有滿足的人數
        if(n%2==0){ //人數一定要恰好一半
            for(int i=half_weight; i>=0; i--){
                if(dp[i][n/2]){
                    ans.first=i;
                    ans.second=total_weight-i;
                    break;
                }
            }
        }
        else{
            for(int i=half_weight; i>=0; i--){
                if(dp[i][n/2]||dp[i][n/2+1]){
                    ans.first=i;
                    ans.second=total_weight-i;
                    break;
                }
            }
        }
        cout<<ans.first<<" "<<ans.second<<endl;
        if(cases!=0) cout<<endl; 
        
    }
    return 0;
}