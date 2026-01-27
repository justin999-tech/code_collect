//Uva 10254
//#大數 #dp
#include<bits/stdc++.h>
using namespace std;
class BigInt{
public:
    vector<int> val; //倒序填入
    BigInt(int n=0){
        if(n==0){
            this->val.push_back(0);
        }
        while(n>0){
            this->val.push_back(n%10);
            n/=10;
        }
    }

    //parameter is possibly BigInt
    BigInt operator+(const BigInt& b) const{ // 2nd const means you can't modify this (ex: this->val)
        BigInt res;
        res.val.clear();
        int carry = 0;
        for(size_t i=0 ; i<max(this->val.size(),b.val.size()) || carry ; i++){
            int sum = carry + (i < val.size() ? val[i] : 0) + (i<b.val.size() ? b.val[i] : 0);
            res.val.push_back(sum%10);
            carry = sum/10;
        }
        return res;
    }

    //parameter is only int 
    BigInt operator*(const int& b) const{
        BigInt res;
        res.val.clear();
        int carry = 0;
        for(size_t i=0; i<this->val.size() || carry ; i++){
            long long cur = carry + (long long)(i<this->val.size() ? val[i] : 0)*b;
            res.val.push_back(cur%10);
            carry = cur/10;
        }
        return res;
    }

    bool operator<(const BigInt& b) const{
        if(val.size()!=b.val.size()) return val.size()<b.val.size();
        for(int i=val.size()-1; i>=0; i--){
            if(this->val[i]!=b.val[i]) return val[i]<b.val[i];
        }
        return false;
    }

    void print(){
        if(val.empty()){
            cout<<0<<endl;
            return;
        }
        for(int i=val.size()-1; i>=0; i--){
            cout<<val[i];
        }
        cout<<endl;
    }
};
int main(){
    vector<BigInt> dp(10001);
    dp[0]=BigInt(0);
    dp[1]=BigInt(1);
    //從2算到10000個盤子，最後用查表print答案
    //創建bottom-up dp
    for(int i=2; i<=10000; i++){
        BigInt min = dp[i-1]*2 + BigInt(1);  
        // 我嘗試把 i 分割成：先用4根柱子搬 (i-j) 個，剩下 j 個用3根柱子搬
        // 套入遞迴式： 2 * dp[i-j] + (2^j - 1)
        BigInt power_j = 2; //放在j-for-loop外面才不會TLE，因為才不會重複計算
        for(int j=2 ;j<i; j++){
            power_j = power_j*2;//每次只乘一次，效率高
            BigInt power_j_minus_1 = power_j;
            power_j_minus_1.val[0]--;
            BigInt total = dp[i-j]*2 + power_j_minus_1;
            //經過數學證明可知洽有一極小值->U形函數
            if(total<min){
                min = total;
            }
            else{
                break;
            }
        }
        dp[i]=min;
        if (i % 500 == 0){
            cerr << "Progress: " << (i/100)<<"% finished (i=" <<i<<")"<< endl;
        }
    }
    int ask;
    while(cin>>ask){
        dp[ask].print();
    }
    return 0;
}











/*
以下為我原本的代碼，但對於數字太大會爆掉因為2^64-1就已經long long了，並且實際丟到judge上是TLE
#include<bits/stdc++.h>
using namespace std;
long long f(int n, vector<long long>& dp){
    if(n==0) return 0;
    if(n==1) return 1;
    if(n==2) return 3;
    if(dp[n]!=-1) return dp[n];
    long long least=LLONG_MAX;
    for(int k=1; k<n; k++){
        long long tmp=0;
        if(dp[k]==-1){
            tmp=2*f(k,dp)+pow(2,n-k)-1;
        }
        else{
            tmp=2*dp[k]+pow(2,n-k)-1;
        }
        least=min(least,tmp);
    }
    dp[n]=least;
    return least;
}
int main(){
    int n;
    while(cin>>n){
        //dp[i]:i the least move of i discs
        vector<long long> dp(n+1,-1);
        dp[0]=0;
        dp[1]=1;
        dp[2]=3;
        long long ans = f(n,dp);
        cout<<ans<<endl;
    }
    return 0;
}
*/
