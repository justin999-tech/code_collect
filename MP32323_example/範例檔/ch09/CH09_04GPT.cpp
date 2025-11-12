#include <iostream>
using namespace std;

int fibonacciSearch(int arr[], int n, int x) {
    int fibM2 = 0; // (m-2)'th Fibonacci number
    int fibM1 = 1; // (m-1)'th Fibonacci number
    int fib = fibM2 + fibM1; // m'th Fibonacci number

    while (fib < n) {
        fibM2 = fibM1;
        fibM1 = fib;
        fib = fibM2 + fibM1;
    }

    int offset = -1; // to indicate the offset for range splitting

    while (fib > 1) {
        int i = min(offset + fibM2, n - 1);

        // Compare x with the last element of the current range
        if (arr[i] < x) {
            fib = fibM1;
            fibM1 = fibM2;
            fibM2 = fib - fibM1;
            offset = i;
        } else if (arr[i] > x) {
            fib = fibM2;
            fibM1 = fibM1 - fibM2;
            fibM2 = fib - fibM1;
        } else {
            return i; // Element found
        }
    }

    if (fibM1 && arr[offset + 1] == x)
        return offset + 1; // Element found

    return -1; // Element not found
}

int main() {
    int data[] = {5, 7, 12, 23, 25, 37, 48, 54, 68, 77, 59, 91, 99, 102, 110, 118, 120, 130, 135, 136, 150};
    int n = sizeof(data) / sizeof(data[0]);

    while (true) {
        int target;
        cout << "請輸入您想要搜尋的鍵值 (-1 結束搜尋): ";
        cin >> target;

        if (target == -1) {
            cout << "結束搜尋" << endl;
            break;
        }

        int result = fibonacciSearch(data, n, target);

        if (result != -1) {
            cout << "找到目標鍵值 " << target << " 在索引 " << result << " 位置" << endl;
        } else {
            cout << "目標鍵值 " << target << " 未找到" << endl;
        }
    }

    cout << "資料內容: ";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}

