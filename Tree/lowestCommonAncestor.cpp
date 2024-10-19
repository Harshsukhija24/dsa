#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL || root == p || root == q) {
        return root;
    }

    // Recursively find LCA in left and right subtrees
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    // If both left and right are not NULL, p and q are in different subtrees
    if (left != NULL && right != NULL) {
        return root;
    }

    // Otherwise, return the non-NULL child
    return (left != NULL) ? left : right;
}

int main() {
    // Create tree nodes
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    // Set the nodes to find LCA for
    TreeNode* p = root->left; // Node with value 5
    TreeNode* q = root->right; // Node with value 1

    // Find and print the LCA
    TreeNode* lca = lowestCommonAncestor(root, p, q);
    if (lca) {
        cout << "LCA of nodes " << p->val << " and " << q->val << " is: " << lca->val << endl;
    } else {
        cout << "LCA not found." << endl;
    }


    return 0;
}
