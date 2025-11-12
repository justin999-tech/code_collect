#include <iostream>
#include <vector>
using namespace std;

void solve_list(){
    int mod=1e9+7;
    int max_n=1e5;

    vector<int> fib_mod(max_n+1);
    fib_mod[0]=0;
    fib_mod[1]=1;
    for(int i=2; i<=max_n; i++){
        fib_mod[i]=(fib_mod[i-1] + fib_mod[i-2]) % mod;
    }

    int T;
    cin >> T;

    while(T--){
    int n;
    cin >> n;
    cout <<fib_mod[n] << "\n";
    }
}



int main(){
    solve_list();
    return 0;
}