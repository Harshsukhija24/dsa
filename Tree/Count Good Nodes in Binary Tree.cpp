#include <bits/stdc++.h>
using namespace std;


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x),left(NULL),right(NULL){}
};

int countGood(TreeNode* root ,int maxval){
    if(root==NULL){
        return 0;
    }
    int good=0;
    if(root->val>=maxval){
      good=1;
      maxval=root->val;
    }
    good+=countGood(root->left,maxval);
    good+=countGood(root->right,maxval);

    return good;
}

int countGoodNodes(TreeNode* root){
    if(root==NULL){
        return 0;
    }
    return countGood(root,root->val);
}


int main(){
  TreeNode* root=new TreeNode(3);
  root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(5);

    cout << "Number of good nodes: " << countGoodNodes(root) << endl;

    return 0;
}