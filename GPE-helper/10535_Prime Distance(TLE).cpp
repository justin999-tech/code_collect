//Uva 10140
#include<bits/stdc++.h>
using namespace std;
//map<prime, the dist between this prime and the next one>
map<int,int> prime_number;
vector<int> prime(2147483648,-1); //這邊其實就會MLE了 4byte*2^31=8GB
bool is_prime(int num){
    if(num==1) return false;
    for(int i=2; i*i<=num; i++){
        if(num%i==0){
            return false;
        }
    }
    return true;
}
vector<int> solve(int L, int R, vector<int>& v){
    int flag = -1;
    pair<int,int> closest={0,INT_MAX};
    pair<int,int> farest={0,0};
    for(int i=L; i<=R; i++){
        if(prime_number.find(i)!=prime_number.end()){
            if(prime_number[i]<closest.second-closest.first){
                closest.first = i;
                closest.second = i + prime_number[i];
            }
            if(prime_number[i]>farest.second-farest.first){
                farest.first = i;
                farest.second = i + prime_number[i];
            }
            flag=i;
            continue;
        }
        if(prime[i]==0) continue;
        if(prime[i]==-1 && !is_prime(i)) prime[i]=0;
        if(prime[i]==-1 && is_prime(i)){
            if(flag==-1){
                flag=i;
            }
            if(flag!=-1){
                prime_number[flag]=i-flag;
                if(prime_number[flag]<closest.second-closest.first){
                    closest.first=flag;
                    closest.second=i;
                }
                if(prime_number[flag]>farest.second-farest.first){
                    farest.first=flag;
                    farest.second=i;
                }
                flag = i;
            }
        }
    }
    v[0]=closest.first;
    v[1]=closest.second;
    v[2]=farest.first;
    v[3]=farest.second;
    return v;
}
int main(){
    int L;
    int R;
    while(cin>>L>>R){
        vector<int> v(4,0);
        solve(L,R,v);
        if(v[0]==0){
            cout<<"There are no adjacent primes."<<endl;
        }
        else{
            cout<<v[0]<<","<<v[1]<<" are the closest, "<<v[2]<<","<<v[3]<<" are most distant."<<endl;
        }
    }
    return 0;
}
