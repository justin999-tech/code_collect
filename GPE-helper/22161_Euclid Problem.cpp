//Uva10104
// #Euclid
// 擴展歐幾里得演算法 (Extended Euclidean Algorithm, EEA)
// note
#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b, int& x, int& y){
    if(b==0){
        x=1;
        y=0;
        return a; //gcd(a,0)=a
    }
    int x1,y1;
    int tmp=gcd(b,a%b,x1,y1);
    x=y1;
    y=x1-(a/b)*y1;
    return tmp;
}
int main(){
    int a,b;
    while(cin>>a>>b){
        int x,y;
        int res=gcd(a,b,x,y);
        cout<<x<<" "<<y<<" "<<res<<endl;
    }
    return 0;
}