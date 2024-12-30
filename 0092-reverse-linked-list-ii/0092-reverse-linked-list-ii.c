/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int l, int r) {
    if(head==NULL || l==r) return head;
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->val=0;
    dummy->next=head;

    struct ListNode* prev=dummy;   

    for(int i=1; i<l; i++)
        prev = prev->next;
    
    struct ListNode* curr = prev->next;
    struct ListNode* prevNode = NULL;
    struct ListNode* nextNode = NULL;

    for(int i=l; i<=r; i++){
        nextNode = curr->next;
        curr->next = prevNode;
        prevNode = curr;
        curr = nextNode;
    }

    prev->next->next = curr;
    prev->next = prevNode;

    if(l==1)
        head = prevNode;

    free(dummy);

    return head;

}