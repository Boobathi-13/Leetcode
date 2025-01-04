#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     struct TreeNode *left;
//     struct TreeNode *right;
// };

// Queue node structure
struct QueueNode {
    struct TreeNode *treeNode;
    struct QueueNode *next;
};

// Queue structure
struct Queue {
    struct QueueNode *front, *rear;
};

// Create a new queue node
struct QueueNode *newQueueNode(struct TreeNode *treeNode) {
    struct QueueNode *temp = (struct QueueNode *)malloc(sizeof(struct QueueNode));
    temp->treeNode = treeNode;
    temp->next = NULL;
    return temp;
}

// Create an empty queue
struct Queue *createQueue() {
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Enqueue a tree node
void enqueue(struct Queue *q, struct TreeNode *treeNode) {
    struct QueueNode *temp = newQueueNode(treeNode);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

// Dequeue a tree node
struct TreeNode *dequeue(struct Queue *q) {
    if (q->front == NULL) return NULL;
    struct QueueNode *temp = q->front;
    struct TreeNode *treeNode = temp->treeNode;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return treeNode;
}

// Check if the queue is empty
int isEmpty(struct Queue *q) {
    return q->front == NULL;
}

// Function to perform level order traversal
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (root == NULL) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    int **result = (int **)malloc(2000 * sizeof(int *)); // Max nodes = 2000
    *returnColumnSizes = (int *)malloc(2000 * sizeof(int));
    *returnSize = 0;

    struct Queue *q = createQueue();
    enqueue(q, root);

    while (!isEmpty(q)) {
        int levelSize = 0;
        struct Queue *tempQueue = createQueue();
        int *level = (int *)malloc(2000 * sizeof(int));

        while (!isEmpty(q)) {
            struct TreeNode *node = dequeue(q);
            level[levelSize++] = node->val;
            if (node->left) enqueue(tempQueue, node->left);
            if (node->right) enqueue(tempQueue, node->right);
        }

        result[*returnSize] = level;
        (*returnColumnSizes)[*returnSize] = levelSize;
        (*returnSize)++;

        free(q);
        q = tempQueue;
    }

    free(q);
    return result;
}
