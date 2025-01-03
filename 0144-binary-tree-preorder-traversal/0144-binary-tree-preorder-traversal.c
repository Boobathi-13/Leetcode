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
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int index = 0;

    void countNodes(struct TreeNode* node, int* returnSize){
        if (node == NULL) return; 
        (*returnSize)++; 
        countNodes(node->left, returnSize); 
        countNodes(node->right, returnSize); 
    }

    void preorder(struct TreeNode* root, int* arr, int* index){
        if(root==NULL) return;
        arr[(*index)++]=root->val;
        preorder(root->left, arr, index);
        preorder(root->right, arr, index);
    }
    
    countNodes(root, returnSize);
    printf("%d",*returnSize);

    int* arr = (int*)malloc((*returnSize) * sizeof(int));

    preorder(root, arr, &index);
    return arr;
}