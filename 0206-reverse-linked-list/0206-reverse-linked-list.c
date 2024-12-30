/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* Prev = NULL;
    while(head!=NULL){
        struct ListNode* Next = head->next;
        head->next = Prev;
        Prev = head;
        head = Next;
    }
    return Prev;
}