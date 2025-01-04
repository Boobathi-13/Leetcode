/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isUnivalTree(struct TreeNode* root) {
    if (root == NULL) return true; // Base case: empty tree is univalued
    int value = root->val;
    bool res = true;
    void inorder(struct TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);
        if(root->val!=value) res = false;
        inorder(root->right);
    }
    inorder(root);
    return res;
}