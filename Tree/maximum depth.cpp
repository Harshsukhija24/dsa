#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxDepth(TreeNode* root) {
    if (root == NULL) {
        return 0;  
    }
    int leftDepth = maxDepth(root->left);   
    int rightDepth = maxDepth(root->right); 
    
    return max(leftDepth, rightDepth) + 1;  
}

int main() {
   

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    root->right->right->right=new TreeNode(91);

    cout << "Max Depth: " << maxDepth(root) << endl;

    

    return 0;
}
