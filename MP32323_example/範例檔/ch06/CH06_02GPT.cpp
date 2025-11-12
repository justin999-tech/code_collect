#include <iostream>

using namespace std;

// 二元樹節點結構
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// 函數：插入節點到二元樹
TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

// 函數：中序遍歷並輸出二元樹的節點
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    TreeNode* root = nullptr;
    int data;

    cout << "請輸入10個節點的資料:" << endl;

    for (int i = 0; i < 10; i++) {
        cout << "節點 " << i + 1 << ": ";
        cin >> data;
        root = insert(root, data);
    }

    cout << "中序遍歷結果: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}

