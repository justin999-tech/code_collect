## 計算運行時間
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
    auto start = std::chrono::high_resolution_clock::now();

    sleep(3);

    auto finish = std::chrono::high_resolution_clock::now();
    printf("Elapsed time in nanoseconds: %ld ns\n", std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count());
    printf("Elapsed time in microseconds: %ld µs\n", std::chrono::duration_cast<std::chrono::microseconds>(finish-start).count());
    printf("Elapsed time in milliseconds: %ld ms\n", std::chrono::duration_cast<std::chrono::milliseconds>(finish-start).count());
    printf("Elapsed time in seconds: %ld sec\n", std::chrono::duration_cast<std::chrono::seconds>(finish-start).count());
    return 0;
}
```