#include <iostream>

using namespace std;

const int MAX_SIZE = 20;
int queue[MAX_SIZE];
int front = -1;
int rear = -1;

// 函數：新增資料到佇列
void enqueue(int value) {
    if (rear == MAX_SIZE - 1) {
        cout << "佇列已滿，無法新增資料。" << endl;
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = value;
        cout << "已新增 " << value << " 到佇列。" << endl;
    }
}

// 函數：取出佇列前端的資料
void dequeue() {
    if (front == -1) {
        cout << "佇列是空的，無法取出資料。" << endl;
    } else {
        int value = queue[front];
        cout << "取出佇列前端的值：" << value << endl;
        if (front == rear) {
            // 如果佇列中只有一個元素，重設 front 和 rear
            front = -1;
            rear = -1;
        } else {
            front++;
        }
    }
}

// 函數：列出佇列中的所有資料
void displayQueue() {
    if (front == -1) {
        cout << "佇列是空的。" << endl;
    } else {
        cout << "佇列中的資料：";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    char choice;

    do {
        cout << "請輸入操作 (I: 新增資料, G: 取出資料, E: 結束): ";
        cin >> choice;

        switch (choice) {
            case 'I':
                int value;
                cout << "請輸入要新增的值: ";
                cin >> value;
                enqueue(value);
                break;
            case 'G':
                dequeue();
                break;
            case 'E':
                cout << "程式結束。" << endl;
                break;
            default:
                cout << "無效的操作，請重新輸入。" << endl;
        }

    } while (choice != 'E');

    // 列出佇列中的所有資料
    displayQueue();

    return 0;
}

