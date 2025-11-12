#include <iostream>

using namespace std;

// 樣板結構表示鏈結串列的節點
template <class T>
struct Node {
    T data;         // 節點的資料
    Node* next;     // 指向下一個節點的指針

    Node(const T& value) : data(value), next(NULL) {}
};

// 樣板類別表示鏈結串列
template <class T>
class LinkedList {
private:
    Node<T>* head;  // 鏈結串列的頭節點

public:
    LinkedList() : head(NULL) {}

    // 在串列的開頭插入一個新節點
    void insert(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
    }

    // 列印整個串列的內容
    void print() {
        Node<T>* current = head;
        while (current != NULL) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    // 解構函數用於釋放節點的記憶體
    ~LinkedList() {
        while (head != NULL) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList<int> intList; // 創建一個整數型的鏈結串列

    int data;
    cout << "請輸入整數節點數據，輸入-1結束:" << endl;
    while (cin >> data && data != -1) {
        intList.insert(data);
    }

    cout << "整數型鏈結串列: ";
    intList.print();

    return 0;
}

