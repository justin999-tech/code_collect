#include<bits/stdc++.h>
using namespace std;
vector<int> base_prime;
vector<bool> prime_candidate(50005,true);
void precalculate(){
    prime_candidate[0]=false;
    prime_candidate[1]=false;
    for(int i=2; i*i<=50000; i++){
        if(prime_candidate[i]==true){
            for(long long j=(long long)i*i ; j<=50000; j+=i){
                prime_candidate[j]=false;
            }
        }
    }
    // Collect all primes up to 50000
    for(int i=2; i<=50000; i++){
        if(prime_candidate[i]) base_prime.push_back(i);
    }
}
int main(){
    precalculate();
    int L,R;
    while(cin>>L>>R){
        //range_p[i]=true denotes L+i is prime
        vector<bool> range_p(R-L+1,true);
        if(L==1) range_p[0]=false;
        for(int p : base_prime){
            if((long long)p*p>R) break;
            //find the first multiple of prime which >= L
            long long start = ((long long)L+p-1)/p * p; //notice要long long
            if(start == p) start+=p;
            for(long long j=start; j<=R; j+=p){ //notice要long long
                range_p[j-L]=false;
            }
        }
        vector<int> prime_collect;
        for(long long i=L; i<=R; i++){
            if(range_p[i-L]) prime_collect.push_back((int)i);
        }
        if(prime_collect.size()<2){
            cout<<"There are no adjacent primes."<<endl;
            continue;
        }
        pair<int,int> closest = {0,INT_MAX};
        pair<int,int> farest = {0,0};
        for(int i=0; i<=prime_collect.size()-2; i++){
            int dist = prime_collect[i+1] - prime_collect[i];
            if(dist < closest.second-closest.first){
                closest.first=prime_collect[i];
                closest.second=prime_collect[i+1];
            }
            if(dist > farest.second-farest.first){
                farest.first=prime_collect[i];
                farest.second=prime_collect[i+1];
            }
        }
        cout<<closest.first<<","<<closest.second<<" are closest, "<<farest.first<<","<<farest.second<<" are most distant."<<endl;
    }
    return 0;
}