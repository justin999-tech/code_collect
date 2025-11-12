#include <iostream>

using namespace std;

int main() {
    int m, n, p, q;

    // 輸入第一個矩陣的維度
    cout << "請輸入第一個矩陣的維度 (m x n): ";
    cin >> m >> n;

    // 輸入第二個矩陣的維度
    cout << "請輸入第二個矩陣的維度 (p x q): ";
    cin >> p >> q;

    // 檢查這兩個矩陣是否可以相乘
    if (n != p) {
        cout << "矩陣相乘不可能。第一個矩陣的列數必須等於第二個矩陣的行數。" << endl;
        return 1;
    }

    // 輸入第一個矩陣的元素
    int matrix1[m][n];
    cout << "請輸入第一個矩陣的元素:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix1[i][j];
        }
    }

    // 輸入第二個矩陣的元素
    int matrix2[p][q];
    cout << "請輸入第二個矩陣的元素:" << endl;
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            cin >> matrix2[i][j];
        }
    }

    // 進行矩陣相乘
    if (n != p) {
        cout << "矩陣相乘不可能。第一個矩陣的列數必須等於第二個矩陣的行數。" << endl;
    } else {
        int result[m][q];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < q; j++) {
                result[i][j] = 0;
                for (int k = 0; k < n; k++) {
                    result[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }

        // 輸出結果矩陣
        cout << "矩陣相乘結果:" << endl;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < q; j++) {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}

