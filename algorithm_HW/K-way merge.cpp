#include <iostream>      // cin, cout
#include <vector>        // vector
#include <queue>         // priority_queue
#include <tuple>         // tuple
#include <functional>    // greater<>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> k;
    vector<vector<int>> lists(k);

    // 讀入每個 list
    for (int i = 0; i < k; i++) {
        int n;
        cin >> n;
        lists[i].resize(n);
        for (int j = 0; j < n; j++) {
            cin >> lists[i][j];
        }
    }

    // 建立最小堆 (min-heap)
    // tuple: (值, list編號, 該list中位置)
    priority_queue<
        tuple<int,int,int>,
        vector<tuple<int,int,int>>,
        greater<tuple<int,int,int>>
    > pq;

    // 把每個 list 的第一個元素放入 heap
    for (int i = 0; i < k; i++) {
        if (!lists[i].empty()) {
            pq.push({lists[i][0], i, 0});
        }
    }

    vector<int> result;

    // 不斷取出最小值
    while (!pq.empty()) {
        auto [val, i, j] = pq.top();
        pq.pop();
        result.push_back(val);

        // 如果該 list 還有下一個元素，放進 heap
        if (j + 1 < (int)lists[i].size()) {
            pq.push({lists[i][j + 1], i, j + 1});
        }
    }

    // 輸出結果
    for (int i = 0; i < (int)result.size(); i++) {
        if (i > 0) cout << " ";
        cout << result[i];
    }
    cout << "\n";
}
