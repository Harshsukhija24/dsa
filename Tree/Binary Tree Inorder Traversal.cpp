#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Helper function for inorder traversal
void inorderHelper(TreeNode* root, vector<int>& result) {
    if (root == NULL) {
        return;
    }
    inorderHelper(root->left, result);  // Traverse left subtree
    result.push_back(root->val);        // Visit root
    inorderHelper(root->right, result); // Traverse right subtree
}

// Function for inorder traversal
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    inorderHelper(root, result);
    return result;
}

// Function to create a binary tree from a list of values
TreeNode* createList(const vector<int>& values) {
    if (values.empty() || values[0] == -1) return NULL;

    TreeNode* root = new TreeNode(values[0]);
    queue<TreeNode*> q;
    q.push(root);
    
    int i = 1;
    while (!q.empty() && i < values.size()) {
        TreeNode* current = q.front();
        q.pop();

        // Create left child
        if (values[i] != -1) {
            current->left = new TreeNode(values[i]);
            q.push(current->left);
        }
        i++;

        // Ensure we don't go out of bounds
        if (i >= values.size()) break;

        // Create right child
        if (values[i] != -1) {
            current->right = new TreeNode(values[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}

int main() {
    int n;
    cin >> n;
    vector<int> values(n);
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    TreeNode* root = createList(values);
    vector<int> traversal = inorderTraversal(root);

    for (int val : traversal) {
        cout << val << " ";
    }
    return 0;
}
