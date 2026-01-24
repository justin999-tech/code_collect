//d182
#include<bits/stdc++.h>
using namespace std;
map<int,vector<int>> ans;
int main(){
    int n;  //n=2 4 6 8
    while(cin>>n){
        int half_n = n/2;
        int split_base = 1;
        for(int i=0; i<half_n; i++){
            split_base=split_base*10;
        }

        int candidate;
        for(int i=0; i<split_base; i++){
            candidate = i*i;
            int left = candidate/split_base;
            int right = candidate%split_base;
            if(left+right==i){
                ans[n].push_back(candidate);
            }
        }
        for(auto i : ans[n]){
            printf("%0*d",n,i);
            cout<<endl;
        }
    }
    return 0;
}
