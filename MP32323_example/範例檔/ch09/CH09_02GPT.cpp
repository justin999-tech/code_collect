#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// 生成1到150之間的隨機整數，確保不重複
int generateUniqueRandomNumber(int usedNumbers[], int currentIndex) {
    int randomNumber;
    bool isUnique;
    do {
        randomNumber = rand() % 150 + 1;
        isUnique = true;
        for (int i = 0; i < currentIndex; i++) {
            if (usedNumbers[i] == randomNumber) {
                isUnique = false;
                break;
            }
        }
    } while (!isUnique);
    usedNumbers[currentIndex] = randomNumber;
    return randomNumber;
}

// 使用二分搜尋法尋找目標數字
int binarySearch(int arr[], int target, int left, int right) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        cout << "尋找中間元素索引: " << mid << endl;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] < target) {
            cout << "找右半邊" << endl;
            left = mid + 1;
        } else {
            cout << "找左半邊" << endl;
            right = mid - 1;
        }
    }

    return -1;  // 如果找不到，返回-1
}

int main() {
    srand(time(0));  // 用當前時間種子初始化亂數生成器

    const int size = 50;
    int numbers[size];
    int usedNumbers[size] = {0};

    // 生成50個不重複的隨機數並填充數組
    for (int i = 0; i < size; i++) {
        numbers[i] = generateUniqueRandomNumber(usedNumbers, i);
    }

    // 對數組進行排序
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }

    int target;
    cout << "輸入要查找的目標數字：";
    cin >> target;

    int index = binarySearch(numbers, target, 0, size - 1);

    if (index != -1) {
        cout << "找到目標數字 " << target << "，位於索引 " << index << endl;
    } else {
        cout << "未找到目標數字 " << target << endl;
    }

    cout << "生成的不重複隨機數組：" << endl;
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    return 0;
}

