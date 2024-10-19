#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorderHelper(TreeNode* root, vector<int>& result) {
    if (root == NULL) {
        return;
    }
    inorderHelper(root->left, result);  
    result.push_back(root->val);        
    inorderHelper(root->right, result); 
}

bool isValidBST(TreeNode* root) {
    vector<int> inorderValues;
    inorderHelper(root, inorderValues);

    for (int i = 1; i < inorderValues.size(); ++i) {
        if (inorderValues[i] <= inorderValues[i - 1]) {
            return false; 
        }
    }

    return true; 
}

int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
 
    cout << (isValidBST(root) ? "The tree is a valid BST." : "The tree is not a valid BST.") << endl;
    

    return 0;
}





