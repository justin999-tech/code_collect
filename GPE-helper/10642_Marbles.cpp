// Uva 10090 note
// # 擴展歐幾里得演算法 (Extended Euclidean Algorithm, EEA)
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
//gdc(a,b)=gcd(b,a mod b)=...gcd(ans,0) stop!!
ll extend_gcd(ll a, ll b, ll& x0, ll& y0){
    if(b==0){
        x0=1; y0=0;
        return a;
    }
    ll x1,y1;
    ll gcd = extend_gcd(b,a%b,x1,y1);
    x0 = y1; y0=x1-(a/b)*y1;
    return gcd;
}
int main(){
    ll n,c1,n1,c2,n2;
    while(cin>>n && n!=0){
        cin>>c1>>n1>>c2>>n2;
        ll x0,y0;
        ll g=extend_gcd(n1,n2,x0,y0);
        if(n%g!=0){
            cout<<"failed"<<endl;
            continue;
        }
        ll m1_prime=x0*(n/g);
        ll m2_prime=y0*(n/g);
        ll b1 = n2/g;
        ll b2 = n1/g;
        // m1 = m1_prime + t(n2/g) >= 0 ----> t >= -(m1_prime*g)/n2
        // m2 = m2_prime - t(n1/g) >= 0 ----> t <= (m2_prime*g)/n1

        // double t_min = ceil(-m1_prime/b1);
        // double t_max = floor(m2_prime/b2);
        // if(t_min > t_max){
        //上面因為會超過double所以比較的時候會錯誤

        /*
        double t_min_substitute = -(double)x0/b1; 
        double t_max_substitute = (double)y0/b2;  
        if(t_min_substitute>t_max_substitute){
            cout<<"failed"<<endl; 
            continue;
        }
        */

        // 取代原本的 t_min (ceil 邏輯) 直接取double會錯誤，double精度只有到
        ll t_min;
        ll a1 = -m1_prime;
        if (a1 >= 0) t_min = (a1 + b1 - 1) / b1; // 正數向上取整
        else t_min = a1 / b1;                  // 負數向上取整 (C++ 除法特性)

        // 取代原本的 t_max (floor 邏輯)
        ll t_max;
        ll a2 = m2_prime;
        if (a2 >= 0) t_max = a2 / b2;           // 正數向下取整
        else t_max = (a2 - b2 + 1) / b2;        // 負數向下取整
        if(t_min > t_max){
            cout<<"failed"<<endl;
            continue;
        }

        // double candidate_1 = c1*(m1_prime + t_min*b1) + c2*(m2_prime - t_min*b2);
        // double candidate_2 = c1*(m1_prime + t_max*b1) + c2*(m2_prime - t_max*b2);
        // if(candidate_1<=candidate_2){
        //上面會爆掉因為數字太大，可以直接比單位容量成本(c1/n1 vs c2/n2)，交叉相乘比大小
        if(c1*n2<=c2*n1){ //c1比較便宜所以要取t_max(讓t越大越好)
            cout<<m1_prime + t_max*b1<<" "<<m2_prime - t_max*b2<<endl;
        }
        else{
            cout<<m1_prime + t_min*b1<<" "<<m2_prime - t_min*b2<<endl;
        }
    }
    return 0;
}
