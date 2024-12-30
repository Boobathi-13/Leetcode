/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return NULL; // No cycle if the list is empty or has only one node
    }

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    // Step 1: Detect if there's a cycle using the slow and fast pointers
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Cycle detected
            break;
        }
    }

    // If no cycle is detected
    if (fast == NULL || fast->next == NULL) {
        return NULL;
    }

    // Step 2: Find the node where the cycle begins
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow; // The node where the cycle begins
}