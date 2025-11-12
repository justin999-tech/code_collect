#include <iostream>

using namespace std;

// 遞迴函數計算第n項費波那契數
int fibonacci(int n) {
    if (n <= 1) {
        return n;  // 基本情況：n=0時返回0，n=1時返回1
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n;
    cout << "請輸入一個非負整數 n：";
    cin >> n;

    if (n < 0) {
        cout << "請輸入非負整數。" << endl;
    } else {
        cout << "前 " << n << " 項費波那契數為：" << endl;
        for (int i = 0; i <= n; i++) {
            int result = fibonacci(i);
            cout << "第 " << i << " 項費波那契數為 " << result << endl;
        }
    }

    return 0;
}

