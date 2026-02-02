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
        for(int i=0; i<max(val.size(),b.val.size())||carry; i++){
            int sum = carry + (i<val.size()?val[i]:0)+(i<b.val.size()?b.val[i]:0);
            res.val.push_back(sum%10);
            carry = sum/10;
        }
        return res;
    }

    //大數*大數
    BigInt operator*(const BigInt& b) const{
        BigInt res;
        res.val.assign(val.size()+b.val.size(),0);
        for(int i=0; i<val.size(); i++){
            for(int j=0; j<b.val.size(); j++){
                res.val[i+j]+=val[i]*b.val[j];
            }
        }
        //處理進位
        int carry=0;
        for(int i=0; i<val.size()+b.val.size(); i++){
            res.val[i]+=carry;
            carry=res.val[i]/10;
            res.val[i]=res.val[i]%10;  
        }
        while(res.val.size()>1 && res.val.back()==0){
            res.val.pop_back();
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
    // auto start = std::chrono::high_resolution_clock::now();
    int ask;
    // ========== 步驟 1: 預計算組合數 C[n][k] ==========
    // 使用 Pascal's Triangle: C[n][k] = C[n-1][k-1] + C[n-1][k]
    vector<vector<BigInt>> C(301,vector<BigInt>(301));
    for(int i=0; i<=300; i++){
        C[i][0]=1;
        C[i][i]=1;
        for(int j=1; j<i; j++){
            C[i][j]=C[i-1][j-1]+C[i-1][j];
        }
    }
    // ========== 步驟 2: 預計算動態規劃計算 T[i] ==========
    // T[i] = 使用恰好 i 個有標記節點可以構成的二元樹數量
    vector<BigInt> T(301);
    T[0]=BigInt(1);
    T[1]=BigInt(1);
    // 遞推公式: T(n) = n × Σ(k=0 to n-1) [C(n-1, k) × T(k) × T(n-1-k)]
    // 解釋：
    // - 任意一個元素都可以作為根 (n 種選擇)
    // - 從剩餘 n-1 個元素中選 k 個放到左子樹: C(n-1, k)
    // - 左子樹的構建方式: T(k)
    // - 右子樹的構建方式: T(n-1-k)
    for(int n=2; n<=300; n++){
        BigInt tmp=BigInt(0);
        for(int k=0; k<=n-1; k++){
            tmp=tmp+(C[n-1][k]*T[k]*T[n-1-k]);
        }
        tmp=tmp*n;
        T[n]=tmp;
        if(n%30==0){
            cerr<<(n/3)<<"% finished"<<endl;
        }
    }
    while(cin>>ask && ask!=0){
        print(T[ask]);
        cout<<endl;
    }
    // auto finish = std::chrono::high_resolution_clock::now();
    // printf("Elapsed time in milliseconds: %ld ms\n", std::chrono::duration_cast<std::chrono::milliseconds>(finish-start).count());
    return 0;
}