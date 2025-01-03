/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    if (root == NULL) return 0; // Base case: Empty tree has depth 0
    
    // If one child is NULL, only consider the other child
    if (root->left == NULL) return 1 + maxDepth(root->right);
    if (root->right == NULL) return 1 + maxDepth(root->left);
    
    // If both children exist, return the maximum depth of the two subtrees
    return 1 + fmax(maxDepth(root->left), maxDepth(root->right));
}