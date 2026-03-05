#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(cin>>n && n!=0){
        if(n==1){
            cout<<1<<endl;
            continue;
        }
        int ans=n;
        bool prime=true;
        for(int i=2; i*i<=n; i++){
            if(n%i==0){
                prime=false;
                while(n%i==0){
                    n/=i;
                }
                ans=ans/i*(i-1);
            }
        }
        if(n>1 && prime==false) ans=ans/n*(n-1); //質因數分解後最多只會有一個數>sqrt(n)
        if(prime==true) ans-=1;
        cout<<ans<<endl;
    }
    return 0;
}