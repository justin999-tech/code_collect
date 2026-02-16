//Uva 10042
#include<bits/stdc++.h>
using namespace std;
//先算sqrt(10^9)以內質數的digits sum
vector<int> prime_digit(100001,-1);
int digit_sum(int a){
    int sum=0;
    while(a!=0){
        sum+=a%10;
        a/=10;
    }
    return sum;
}
void precalculate(){
    for(int i=2; i<=100000; i++){
        bool prime=true;
        for(int j=2; j*j<=i; j++){
            if(i%j==0){
                prime=false;
                break;
            }
        }
        if(prime==false) continue;
        else{
            prime_digit[i]=digit_sum(i);
        }

    }
}
int min_primefactor(int a){
    for(int i=2; i*i<=a; i++){
        if(a%i==0) return i;
    }
    return a;
}
bool is_prime(int a){
    if(a==1 || a==0) return false;
    for(int i=2; i*i<=a; i++){
        if(a%i==0) return false;
    }
    return true;
}
int solve(int n){
    for(int candidate=n+1; candidate<=INT_MAX; candidate++){
        int tmp = candidate;
        int goal = digit_sum(candidate);
        int count = 0;
        while(tmp!=min_primefactor(tmp)){
            count+=prime_digit[min_primefactor(tmp)];
            tmp=tmp/min_primefactor(tmp);
        }
        count+=digit_sum(tmp);
        if(goal==count && is_prime(candidate)==false) return candidate;
    }
}
int main(){
    int cases;
    cin>>cases;
    precalculate();
    int n;
    while(cases--){
        cin>>n;
        cout<<solve(n)<<endl;
    }
    return 0;
}