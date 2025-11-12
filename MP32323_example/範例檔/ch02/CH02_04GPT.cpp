#include <iostream>
using namespace std;

const int MAX_ROWS = 3;
const int MAX_COLS = 3;

// 函數用來將兩個矩陣相加
void matrixAddition(int matrix1[MAX_ROWS][MAX_COLS], int matrix2[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

int main() {
    int matrix1[MAX_ROWS][MAX_COLS];
    int matrix2[MAX_ROWS][MAX_COLS];
    int result[MAX_ROWS][MAX_COLS];

    // 初始化矩陣1
    int value1 = 1;
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            matrix1[i][j] = value1;
            value1++;
        }
    }

    // 初始化矩陣2
    int value2 = 9;
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            matrix2[i][j] = value2;
            value2++;
        }
    }

    // 呼叫函數執行矩陣相加
    matrixAddition(matrix1, matrix2, result, MAX_ROWS, MAX_COLS);

    // 輸出相加後的結果
    cout << "矩陣1：" << endl;
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            cout << matrix1[i][j] << " ";
        }
        cout << endl;
    }

    cout << "矩陣2：" << endl;
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            cout << matrix2[i][j] << " ";
        }
        cout << endl;
    }

    cout << "相加後的結果：" << endl;
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

