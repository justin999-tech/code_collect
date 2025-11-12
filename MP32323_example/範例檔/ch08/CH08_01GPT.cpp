#include <iostream>

using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false; // ノㄓ浪代セ近琌Τユ传
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // ユ传 arr[j] ㎝ arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }

        // 狦セ近⊿Τユ传ボ计竒Τ矗玡挡
        if (!swapped) {
            break;
        }

        // 块セ近逼计
        cout << "逼筁祘: ";
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arr[] = {6, 5, 9, 7, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "﹍计: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    bubbleSort(arr, n);

    cout << "程沧逼挡狦: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

