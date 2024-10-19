#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Helper function to check if two trees are mirrors of each other
bool isMirror(TreeNode* tree1, TreeNode* tree2) {
    if (tree1 == NULL && tree2 == NULL) return true;
    if (tree1 == NULL || tree2 == NULL) return false;

    return (tree1->val == tree2->val)
        && isMirror(tree1->left, tree2->right)
        && isMirror(tree1->right, tree2->left);
}

// Function to check if the tree is symmetric
bool isSymmetric(TreeNode* root) {
    return isMirror(root, root);
}

int main() {
    // Create tree nodes
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    // Check if the tree is symmetric
    bool symmetric = isSymmetric(root);
    cout << "The tree is " << (symmetric ? "symmetric." : "not symmetric.") << endl;

    

    return 0;
}
