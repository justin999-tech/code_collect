#include <iostream>
using namespace std;

void hello(int a) {
    // 使用 while (true) 來創造無窮迴圈
    // 這不會消耗堆疊記憶體，會一直跑下去直到你手動強制停止 (Ctrl+C)
    while (true) {
        // 可以在這裡印出東西證明它在跑，但小心 I/O 會拖慢速度
         cout << "Hello " ; 
    }
}

int main() {
    hello(10);
    return 0;
}