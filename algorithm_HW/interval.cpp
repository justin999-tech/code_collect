#include <bits/stdc++.h>
using namespace std;

/*
  迭代式 Segment Tree（區間最大值 + 單點更新）
  - 內部結構：長度為 2*n 的陣列 t
    * t[n ... 2n-1] 放原陣列（葉節點）
    * t[1 ... n-1]  放內部節點（父 = max(左子, 右子)）
  - 建樹：O(n)
  - 單點更新：O(log n)
  - 區間查詢：O(log n)（含端點 [l, r]）
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    if (!(cin >> n >> q)) return 0;
    vector<long long> t(2 * n); // 2*n 的扁平樹

    // 1) 建樹：先把原始值放到葉子（t[n ... 2n-1]）
    for (int i = 0; i < n; ++i) cin >> t[n + i];
    // 自底向上推父節點
    for (int i = n - 1; i > 0; --i) t[i] = max(t[i << 1], t[i << 1 | 1]);

    // 2) 單點更新：把第 idx 個元素改成 x（題目 idx 為 1-based）
    auto point_update = [&](int idx, long long x) {
        int p = idx - 1 + n; // map 到葉子：1-based → 0-based → +n
        t[p] = x;            // 更新葉子
        for (p >>= 1; p > 0; p >>= 1) // 一路往上
            t[p] = max(t[p << 1], t[p << 1 | 1]); // 父 = max(左,右)
    };

    // 3) 區間最大查詢：[l, r]（含端點）
    auto range_max = [&](int l, int r) {
        int L = l - 1 + n, R = r - 1 + n; // 都 map 到葉子
        long long ans = LLONG_MIN;
        while (L <= R) {
            if (L & 1) ans = max(ans, t[L++]);   // L 是右子 → 先收，再 L++
            if (!(R & 1)) ans = max(ans, t[R--]); // R 是左子 → 先收，再 R--
            L >>= 1; R >>= 1;                    // 往上（父層）
        }
        return ans;
    };

    // 4) 處理 q 個操作
    for (int _ = 0; _ < q; ++_) {
        char typ; cin >> typ;
        if (typ == 'Q') {
            int l, r; cin >> l >> r;
            cout << range_max(l, r) << '\n';
        } else if (typ == 'U') {
            int i; long long x; cin >> i >> x;
            point_update(i, x);
        } else {
            // 若題目只有 Q/U，這裡通常不會進來
        }
    }
    return 0;
}






