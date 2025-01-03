/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int index = 0;

    void countNodes(struct TreeNode* node, int* returnSize){
        if (node == NULL) return; 
        (*returnSize)++; 
        countNodes(node->left, returnSize); 
        countNodes(node->right, returnSize); 
    }

    void inorder(struct TreeNode* root, int* arr, int* index){
        if(root==NULL) return;
        inorder(root->left, arr, index);
        arr[(*index)++]=root->val;
        inorder(root->right, arr, index);
    }
    
    countNodes(root, returnSize);
    printf("%d",*returnSize);

    int* arr = (int*)malloc((*returnSize) * sizeof(int));

    inorder(root, arr, &index);
    return arr;
}