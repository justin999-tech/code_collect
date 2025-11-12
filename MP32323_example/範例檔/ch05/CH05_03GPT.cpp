#include <iostream>

using namespace std;

const int MAX_SIZE = 10; // 環形佇列的最大容量

class CircularQueue {
private:
    int queue[MAX_SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    // 函數：檢查環形佇列是否為空
    bool isEmpty() {
        return front == -1;
    }

    // 函數：檢查環形佇列是否已滿
    bool isFull() {
        return (rear + 1) % MAX_SIZE == front;
    }

    // 函數：新增資料到環形佇列
    void enqueue(int value) {
        if (isFull()) {
            cout << "環形佇列已滿，無法新增資料。" << endl;
        } else {
            if (isEmpty()) {
                front = 0;
            }
            rear = (rear + 1) % MAX_SIZE;
            queue[rear] = value;
            cout << "已新增 " << value << " 到環形佇列。" << endl;
        }
    }

    // 函數：取出環形佇列的資料
    int dequeue() {
        if (isEmpty()) {
            cout << "環形佇列是空的，無法取出資料。" << endl;
            return -1; // 表示環形佇列是空的
        } else {
            int value = queue[front];
            if (front == rear) {
                front = -1;
                rear = -1;
            } else {
                front = (front + 1) % MAX_SIZE;
            }
            return value;
        }
    }

    // 函數：列出環形佇列的所有資料
    void displayQueue() {
        if (isEmpty()) {
            cout << "環形佇列是空的。" << endl;
        } else {
            int current = front;
            cout << "環形佇列中的資料：";
            while (current != rear) {
                cout << queue[current] << " ";
                current = (current + 1) % MAX_SIZE;
            }
            cout << queue[rear] << endl;
        }
    }
};

int main() {
    CircularQueue cq;
    int choice;

    do {
        cout << "請輸入操作 (-1: 結束, -2: 取出資料, 其他數字: 新增資料): ";
        cin >> choice;

        if (choice == -1) {
            cout << "列出所有序列資料：" << endl;
            cq.displayQueue();
        } else if (choice == -2) {
            if (!cq.isEmpty()) {
                int dequeuedValue = cq.dequeue();
                cout << "取出環形佇列的值：" << dequeuedValue << endl;
            } else {
                cout << "環形佇列是空的，無法取出資料。" << endl;
            }
        } else {
            cq.enqueue(choice);
        }
    } while (choice != -1);

    cout << "程式結束。" << endl;

    return 0;
}

