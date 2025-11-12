#include <iostream>

using namespace std;

// 定義節點結構
struct Node {
    int data;
    Node* next;
};

// 定義堆疊類別
class Stack {
public:
    Stack() {
        top = nullptr;
    }

    // 推入元素到堆疊
    void push(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    // 彈出堆疊頂部元素
    void pop() {
        if (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        } else {
            cout << "堆疊為空，無法彈出元素。" << endl;
        }
    }

    // 輸出堆疊內的所有元素
    void display() {
        Node* current = top;
        cout << "堆疊內的元素：";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

private:
    Node* top;
};

int main() {
    Stack stack;
    int choice, value;

    do {
        cout << "選擇操作：" << endl;
        cout << "1. 推入(push)元素" << endl;
        cout << "2. 彈出(pop)元素" << endl;
        cout << "3. 顯示堆疊內的元素" << endl;
        cout << "0. 離開" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "輸入要推入的元素：";
                cin >> value;
                stack.push(value);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                stack.display();
                break;
            case 0:
                cout << "程式結束。" << endl;
                break;
            default:
                cout << "輸入無效選項，請重新輸入。" << endl;
        }
    } while (choice != 0);

    return 0;
}

