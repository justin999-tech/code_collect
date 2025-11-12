#include <iostream>

int main() {
    // 使用巢狀的 for 迴圈生成九九乘法表
  
    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= 9; ++j) {
            // 計算並輸出乘法結果
            int result = i * j;
            std::cout << i << " x " << j << " = " << result << "\t";
        }
        // 換行到下一個行
        std::cout << std::endl;
    }

    return 0;
}

