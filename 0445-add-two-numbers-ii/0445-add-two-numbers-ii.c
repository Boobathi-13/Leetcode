/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

void push(struct ListNode** Stack, int* top, int val) {
    Stack[++(*top)] = newNode(val);
}

struct ListNode* pop(struct ListNode** Stack, int* top) {
    return (*top >= 0) ? Stack[(*top)--] : NULL;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* Stack1[101];
    struct ListNode* Stack2[101];
    int top1 = -1, top2 = -1;

    while (l1) {
        push(Stack1, &top1, l1->val);
        l1 = l1->next;
    }
    
    while (l2) {
        push(Stack2, &top2, l2->val);
        l2 = l2->next;
    }

    struct ListNode* result = NULL;
    int carry = 0;

    while (top1 >= 0 || top2 >= 0 || carry) {
        int sum = carry;
        if (top1 >= 0) sum += pop(Stack1, &top1)->val;
        if (top2 >= 0) sum += pop(Stack2, &top2)->val;
        
        carry = sum / 10;
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = sum % 10;
        newNode->next = result;
        result = newNode;
    }
    
    return result;
}