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
void insert(TreeNode*& root, int value) {
    TreeNode* newNode = new TreeNode(value);
    if (root == nullptr) {
        root = newNode;
        return;
    }
    TreeNode* current = root;
    TreeNode* backup = nullptr;

    while (current != nullptr) {
        backup = current;
        if (value < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (value < backup->data) {
        backup->left = newNode;
    } else {
        backup->right = newNode;
    }
}

// 中序遍歷
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// 前序遍歷
void preorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// 後序遍歷
void postorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

int main() {
    TreeNode* root = nullptr;
    int data[] = {7, 4, 1, 5, 16, 8, 11, 12, 15, 9, 2};

    for (int i = 0; i < 11; i++) {
        insert(root, data[i]);
    }

    cout << "原始數據: ";
    for (int i = 0; i < 11; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    cout << "中序走訪結果: ";
    inorderTraversal(root);
    cout << endl;

    cout << "前序走訪結果: ";
    preorderTraversal(root);
    cout << endl;

    cout << "後序走訪結果: ";
    postorderTraversal(root);
    cout << endl;

    return 0;
}

