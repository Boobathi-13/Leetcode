/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int diameterOfBinaryTree(struct TreeNode* root) {
    int dia = 0;
    int getWidth(struct TreeNode* root){
        if(root==NULL) return 0;
        int lw = getWidth(root->left);
        int rw = getWidth(root->right);

        dia = fmax(dia, (lw+rw));

        return (int)fmax(lw, rw) + 1;

    }
    getWidth(root);
    return dia;
}