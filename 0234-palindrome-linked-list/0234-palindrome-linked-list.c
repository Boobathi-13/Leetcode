/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    struct ListNode* reverse(struct ListNode* head){
        struct ListNode* Prev = NULL;
        while(head!=NULL){
            struct ListNode* Next = head->next;
            head->next = Prev;
            Prev = head;
            head = Next;
        }
        return Prev;
    }

    struct ListNode *slow=head, *fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }

    struct ListNode* fhalf = head;
    struct ListNode* shalf = reverse(slow);

    bool isPalin = true;
    while(shalf!=NULL){
        if(fhalf->val!=shalf->val){
            isPalin = false;
            break;
        }
        fhalf = fhalf->next;
        shalf = shalf->next;
    }
    return isPalin;
}