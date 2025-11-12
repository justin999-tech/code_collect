#include <iostream>
#include <string>

using namespace std;

// 學生節點結構
struct StudentNode {
    string name;
    int score;
    StudentNode* next;
};

// 函數用於列印學生成績和名字
void printScores(StudentNode* head) {
    StudentNode* current = head;
    int studentNumber = 1;

    while (current != NULL) {
        cout << "學生 " << studentNumber << " 的名字: " << current->name << endl;
        cout << "學生成績: " << current->score << endl;
        current = current->next;
        studentNumber++;
    }
}

int main() {
    StudentNode* head = NULL; // 鏈表的頭節點

    // 使用者輸入五個學生成績和名字
    for (int i = 1; i <= 5; i++) {
        StudentNode* newStudent = new StudentNode;
        cout << "輸入學生 " << i << " 的名字: ";
        cin >> newStudent->name;
        cout << "輸入學生 " << i << " 的成績: ";
        cin >> newStudent->score;
        newStudent->next = NULL;

        // 將新學生節點插入到鏈表
        if (head == NULL) {
            // 如果鏈表是空的，將新學生設置為頭節點
            head = newStudent;
        } else {
            // 否則，找到最後一個節點，並將新學生連接到最後一個節點
            StudentNode* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newStudent;
        }
    }

    // 列印學生成績和名字
    cout << "學生成績和名字列表：" << endl;
    printScores(head);

    // 釋放動態分配的記憶體
    StudentNode* current = head;
    while (current != NULL) {
        StudentNode* nextStudent = current->next;
        delete current;
        current = nextStudent;
    }

    return 0;
}

