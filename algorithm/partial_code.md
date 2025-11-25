``` cpp
int Find_Set(int x) {
    int cur = x;

    // 1️⃣ 先一路往上找 root，同時紀錄路上的節點
    vector<int> path;           
    while (parent[cur] != cur) {
        path.push_back(cur);    
        cur = parent[cur];      
    }
    int root = cur;             

    // 2️⃣ 做 path compression：讓路上所有點直接指向 root
    for (int v : path) {
        parent[v] = root;
    }

    return root;
}
```

```cpp
vector<bool> visited(n, false);
stack<int> st;
st.push(s);
while (!st.empty()) {
    int u = st.top();
    st.pop();

    if (visited[u]) continue;   

    visited[u] = true;
    
    cout << u << " ";

    // 把 u 的鄰居們丟進 stack
    for (int v : Adj[u]) {
        if (!visited[v]) {
            st.push(v);
        }
    }
}

```