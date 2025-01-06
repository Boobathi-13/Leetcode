/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if(p==NULL && q==NULL) return true;
    if (p==NULL || q==NULL) return false;
    struct TreeNode* queue1[220];
    struct TreeNode* queue2[220];
    int front=0, rear=0;
    queue1[rear]=p;
    queue2[rear]=q;
    rear++;
    while(front<rear){
        struct TreeNode* current1=queue1[front];
        struct TreeNode* current2=queue2[front];
        front++;

        if(current1==NULL && current2==NULL) continue;
        if(current1==NULL || current2==NULL || current1->val != current2->val) return false;

        queue1[rear] = current1->left;
        queue2[rear] = current2->left;
        rear++;

        queue1[rear] = current1->right;
        queue2[rear] = current2->right;
        rear++;
    }
    return true;
}