/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode)); // Create a dummy node
    dummy->next = head; // Point dummy to head
    struct ListNode* temp = dummy; // Use temp to traverse
    int size = 0;
    
    // Calculate the size of the list
    while (head != NULL) {
        size++;
        head = head->next;
    }

    head = dummy->next; // Reset head to the original head

    // Traverse again to find the (size-n)th node
    for (int i = 0; i < size - n; i++) {
        temp = temp->next;
    }
    
    // Remove the nth node from the end
    temp->next = temp->next->next;
    
    return dummy->next; // Return the modified list starting from the original head
}
