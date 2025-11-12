#include <iostream>

int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n;
    std::cout << "請輸入要計算的費伯那數列項數: ";
    std::cin >> n;

    if (n < 0) {
        std::cout << "項數必須為正整數。" << std::endl;
    } else {
        int result = fibonacci(n);
        std::cout << "第 " << n << " 項費伯那數列的值是: " << result << std::endl;
    }

    return 0;
}

