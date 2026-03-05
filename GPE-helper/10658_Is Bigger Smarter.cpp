#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Elephant {
    int w, s, id;
};

// 排序邏輯：體重升序；若體重相同，智商降序
bool compare(Elephant a, Elephant b) {
    if (a.w != b.w) return a.w < b.w;
    return a.s > b.s;
}

int main() {
    vector<Elephant> e;
    int w, s, idx = 1;
    while (cin >> w >> s) {
        e.push_back({w, s, idx++});
    }

    sort(e.begin(), e.end(), compare);

    int n = e.size();
    vector<int> dp(n, 1);    // dp[i] 表示以第 i 隻大象結尾的最長序列長度
    vector<int> parent(n, -1); // 用來回溯路徑
    int max_len = 0, last_idx = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            // 嚴格條件：體重增加且智商減少
            if (e[i].w > e[j].w && e[i].s < e[j].s) {
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
        }
        if (dp[i] > max_len) {
            max_len = dp[i];
            last_idx = i;
        }
    }

    // 輸出結果
    cout << max_len << endl;
    vector<int> res;
    while (last_idx != -1) {
        res.push_back(e[last_idx].id);
        last_idx = parent[last_idx];
    }
    for (int i = res.size() - 1; i >= 0; i--) {
        cout << res[i] << endl;
    }

    return 0;
}