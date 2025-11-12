#include <iostream>

using namespace std;

int main() {
    // 宣告一個2x2的二維陣列，表示二階行列式的元素
    int matrix[2][2];

    cout << "請輸入二階行列式的元素：" << endl;

    // 輸入元素的值
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << "輸入 a" << i + 1 << j + 1 << ": ";
            cin >> matrix[i][j];
        }
    }

    // 輸出二階行列式的格式
    cout << "二階行列式的格式如下：" << endl;
    cout << " | " << matrix[0][0] << "  " << matrix[0][1] << " | " << endl;
    cout << " | " << matrix[1][0] << "  " << matrix[1][1] << " | " << endl;

    // 計算二階行列式的值
    int determinant = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);

    // 輸出結果
    cout << "二階行列式的值為：" << determinant << endl;

    return 0;
}

