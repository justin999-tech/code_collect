#include<bits/stdc++.h>
using namespace std;
string input;
int cur; //use nest structure to read we need global indicator
vector<long long> parse(int n){
    cur++; //skip '['
    int sign =1;
    long long num=0;
    vector<long long> tmp(n);
    if(input[cur]=='-'){
        sign = -sign;
        cur++;
    }
    //read num
    while(isdigit(input[cur])){
        num = num*10+(input[cur]-'0');
        cur++;
    }
    num=sign*num;
    if(input[cur]==']'){
        for(int i=0; i<n; i++){
            tmp[i]=num;
        }
        return tmp;
    }
    else{
        if(input[cur])
    }

}
int main(){
    int n;
    while(cin>>input>>n){
        cur=0; //In the begin, pointer is at idx 0;
        vector<long long> res(n);
        res=parse(n);
        for(int i=0; i<n; i++){
            if(i!=n-1) cout<<res[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}