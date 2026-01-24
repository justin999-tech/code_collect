#include <iostream>
#include <fstream>

int main() {
    // 建立或覆蓋 10655.txt
    std::ofstream fout("10655.txt");
    
    int n = 1000;
    fout << n << "\n";
    
    // 產生從 1,000,000 開始的連續數字
    // 最小的三數之和 a+b+c 至少是 3,000,000
    // 但最大的 d 只有 1,000,999
    // 這保證了 a+b+c = d 永遠不成立
    for (int i = 0; i < n; ++i) {
        fout << 1000000 + i << "\n";
    }
    
    fout << "0\n"; // 結束標記
    fout.close();
    
    std::cout << "惡夢級測資 (N=1000, 無解) 已產生至 10655.txt" << std::endl;
    return 0;
}