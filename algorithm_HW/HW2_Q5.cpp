#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

double median(const vector<int>& X, const vector<int>& Y) {
    int n = (int)X.size();              
    int lo = 0, hi = n;                 

    while (lo <= hi) {
        int i = (lo + hi) / 2;
        int j = n - i;                 

        int Lx = (i == 0) ? INT_MIN : X[i - 1];
        int Rx = (i == n) ? INT_MAX : X[i];
        int Ly = (j == 0) ? INT_MIN : Y[j - 1];
        int Ry = (j == n) ? INT_MAX : Y[j];

        // 命中正確切割：左半最大 ≤ 右半最小
        if (Lx <= Ry && Ly <= Rx) {
            int leftMax  = max(Lx, Ly);
            int rightMin = min(Rx, Ry);
            return (leftMax + rightMin) / 2.0; // 偶數個 → 取平均
        }
        // i 太大：X 左半拿太多，Lx 太大，讓 i 往左縮
        else if (Lx > Ry) {
            hi = i - 1;
        }
        // i 太小：X 左半拿太少，Ly 太大（Y 還留太多在左邊），讓 i 往右擴
        else {
            lo = i + 1;
        }
    }
}

// --- 小小測試 ---
int main() {
    vector<int> X = {1, 4, 7, 10};
    vector<int> Y = {2, 3, 8, 12}; // 總 8 個：1,2,3,4,7,8,10,12
    cout << fixed << setprecision(1)
         << "even-median = " << median(X, Y) << "\n"; // 介於第4和第5 → (4+7)/2 = 5.5 
    return 0;
}
