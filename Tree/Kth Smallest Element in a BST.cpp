#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorder(TreeNode* root, int K, int& count, int& result) {
    if (root == NULL) return;
    
    inorder(root->left, K, count, result);
    
    count++;
    if (count == K) {
        result = root->val;
        return;
    }
    
    inorder(root->right, K, count, result);
}

int kthSmallest(TreeNode* root, int K) {
    int count = 0;
    int result = -1;
    inorder(root, K, count, result);
    return result;
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);

    int k = 2;
    cout << "The " << k << "rd smallest element is " << kthSmallest(root, k) << endl;

    return 0;
}
