//d438
#include<bits/stdc++.h>
using namespace std;
bool check_digit_prime(int ask, vector<int>& whether_prime){
    if(ask==1 || whether_prime[ask]==0){
        return false;
    }
    if(ask==2 || ask==3){
        return true;
    }
    for(int i=2; i*i<=ask; i++){
        if(ask%i==0){
            whether_prime[ask]=0; //it's not prime
            return false;
        }
    }
    whether_prime[ask]=1;
    //deal with the sum of each digit
    int sum=0;
    int base=10;
    while(ask!=0){
        sum+=ask%base;
        ask/=10; //往右移一格
    }
    //whether sum is prime
    if(sum==0 || sum==1 || whether_prime[sum]==0){
        return false;
    }
    if(sum==2 || sum==3 || whether_prime[sum]==1){
        return true;
    }
    for(int i=2; i*i<=sum; i++){
        if(sum%i==0){
            whether_prime[ask]=0; //it's not prime
            return false;
        }
    }
    whether_prime[sum]=1;
    return true;
}
int main(){
    int num; //測資數量
    scanf("%d",&num);
    vector<int> prefix_count(1000001,0);
    vector<int> whether_prime(1000001,-1); //初始化原本都未知->-1
    whether_prime[0]=0;
    whether_prime[1]=0;
    whether_prime[2]=1;
    whether_prime[3]=1;
    for(int i=1 ; i<=1000000 ; i++){
        if(check_digit_prime(i,whether_prime)){
            prefix_count[i]=prefix_count[i-1]+1;
        }
        else{
            prefix_count[i]=prefix_count[i-1];
        }
    }
    while(num--){
        int left, right;
        scanf("%d",&left);
        scanf("%d",&right);
        int ans = prefix_count[right]-prefix_count[left-1];
        printf("%d",ans);
        cout<<endl;
    }
    return 0;
}