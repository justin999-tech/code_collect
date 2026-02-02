// Uva 10007
// #big number #卡特蘭數 (Catalan Number) #dp
#include<bits/stdc++.h>
using namespace std;
class BigInt{
public:
    vector<int> val;
    BigInt(int n=0){
        if(n==0) val.push_back(0);
        while(n!=0){
            val.push_back(n%10);
            n/=10;
        }
    }

    BigInt operator+(const BigInt& b) const{
        BigInt res;
        res.val.clear(); //去除掉default constructor's 0;
        int carry = 0;
        for(int i=0; i<=max(this->val.size(),b.val.size())||carry; i++){
            int sum = carry + (i<val.size()?val[i]:0)+(i<b.val.size()?b.val[i]:0);
            res.val.push_back(sum%10);
            carry = sum/10;
        }
        return res;
    }

    BigInt operator*(const int b) const{
        BigInt res;
        res.val.clear();
        int carry = 0;
        for(int i=0; i<val.size()||carry; i++){
            long long product=carry+(i<val.size()?val[i]:0)*b;
            res.val.push_back(product%10);
            carry = product/10;
        }
        return res;
    }
};
void print(BigInt& a){
    //reverse(a.val.begin(),a.val.end()); 這樣連續印2次第2次就會錯了
    for(int i=a.val.size()-1; i>=0; i--) cout<<a.val[i];
}
int main(){
    int n;
    vector<BigInt> dp(301);
    dp[1]=BigInt(1);
    for(int i=2; i<=300; i++){
        dp[i]=BigInt(1);
        for(int j=i+2; j<=2*i; j++){
            dp[i]=dp[i]*j;
        }
        if(i%30==0){
            cerr<<(i/3)<<"% finished"<<endl;
        }
    }
    while(cin>>n && n!=0){
        print(dp[n]);
        cout<<endl;
    }
    return 0;
}