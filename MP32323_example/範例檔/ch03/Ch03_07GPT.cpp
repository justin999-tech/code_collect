#include <iostream>

using namespace std;

// 定義學生成績的結構體
struct Student {
    string name;
    int score;
    Student* next;
};

// 創建並初始化包含5名學生成績的鏈表
Student* createStudentList() {
    Student* head = nullptr;
    Student* current = nullptr;

    for (int i = 1; i <= 5; i++) {
        Student* newStudent = new Student;
        cout << "輸入第" << i << "位學生的姓名: ";
        cin >> newStudent->name;
        cout << "輸入第" << i << "位學生的成績: ";
        cin >> newStudent->score;
        newStudent->next = nullptr;

        if (head == nullptr) {
            head = newStudent;
            current = newStudent;
        } else {
            current->next = newStudent;
            current = newStudent;
        }
    }

    return head;
}

// 遍歷並列印學生成績鏈表
void printStudentList(Student* head) {
    Student* current = head;

    while (current != nullptr) {
        cout << "姓名: " << current->name << "，成績: " << current->score << endl;
        current = current->next;
    }
}

// 連接兩個學生成績鏈表
Student* concatenateStudentLists(Student* list1, Student* list2) {
    if (list1 == nullptr) {
        return list2;
    }

    Student* current = list1;
    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = list2;

    return list1;
}

int main() {
    cout << "輸入第一組學生成績：" << endl;
    Student* list1 = createStudentList();

    cout << "輸入第二組學生成績：" << endl;
    Student* list2 = createStudentList();

    cout << "原始第一組學生成績：" << endl;
    printStudentList(list1);

    cout << "原始第二組學生成績：" << endl;
    printStudentList(list2);

    // 連接兩個學生成績鏈表
    Student* concatenatedList = concatenateStudentLists(list1, list2);

    cout << "連接後的學生成績：" << endl;
    printStudentList(concatenatedList);

    // 釋放內存
    Student* current = concatenatedList;
    while (current != nullptr) {
        Student* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}

