#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    while(cin>>n && n!=0){
        if(n==0){
            cout<<"no"<<endl;
            continue;
        }
        if(n==1){
            cout<<"yes"<<endl;
            continue;
        }
        long long k;
        for(k=1; k*k<n; k++){

        }
        if(k*k==n) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}
/*
用sqrt配合round
#include<bits/stdc++.h>
using namespace std;

int main(){
    // 使用 long long 以防題目數字超過 int 範圍 (21億)
    long long n; 
    
    while(cin >> n && n != 0){
        // 計算開根號的整數部分
        long long root = round(sqrt(n)); 
        
        // 檢查這個整數的平方是否等於原本的 n
        if(root * root == n){
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    return 0;
}
*/