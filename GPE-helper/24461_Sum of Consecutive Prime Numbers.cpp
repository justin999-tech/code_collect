#include<bits/stdc++.h>
using namespace std;
vector<bool> v(10001,true);
vector<int> p;
vector<int> dp(10001,0);
void precalculate(){  //快速算出範圍內的質數
    v[0]=false;
    v[1]=false;
    for(int i=2; i<=10000; i++){
        if(v[i]==true){
            for(int cur=2*i; cur<=10000; cur+=i){
                v[cur]=false;
            }
        } 
    }
    for(int i=2; i<=10000; i++){
        if(v[i]==true){
            p.push_back(i);
        }
    }
}
int main(){
    precalculate();
    for(int i=0; i<p.size(); i++){
        int tmp=0;
        for(int j=i; j<p.size(); j++){
            tmp+=p[j];
            if(tmp>10000) break;
            dp[tmp]++;
        }
    }
    int ask;
    while(cin>>ask && ask!=0){
        cout<<dp[ask]<<endl;
    }
    return 0;
}
