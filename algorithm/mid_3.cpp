#include <bits/stdc++.h>
using namespace std;
//notice that this question is combination not purmutation!
#define MOD 1000000007
int main(){
    int num_case;
    cin>>num_case;
    int num_kind;
    int target; 
    for(int i=0; i<num_case; i++){
        cin>>num_kind;
        cin>>target;
        vector<int> coin(101); //上機考試就是少了（101)
        for(int j=0; j<num_kind; j++){
            cin>>coin[j];
        }
        vector<long long> dp(1001);
        //special base case
        dp[0]=1;
        for(int seq=0;seq<num_kind;seq++){
            for(int p=0; p+coin[seq]<=target;p++){
                dp[p+coin[seq]] = (dp[p+coin[seq]] + dp[p]) % MOD;
            }
        }
        cout << dp[target]  << endl;

    }
    return 0;
}