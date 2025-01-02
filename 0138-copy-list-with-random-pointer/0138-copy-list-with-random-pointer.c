/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

struct Node* copyRandomList(struct Node* head) {

    struct Node* orig = head;

    if (!orig)
        return orig;
    //struct Node* new = NULL;
    while ( orig  != NULL ){
        struct Node* new = (struct Node*)malloc(sizeof(struct Node));
        new->val = orig->val;
        new->next = orig->next;
        new->random = NULL;
        orig->next = new;
        orig = new->next;
    }

    orig = head;
    

    while ( orig != NULL ){
        if ( orig->random ){
            orig->next->random = orig->random->next;
        }
        orig = orig->next->next;        
    }

    orig = head;
    struct Node* newHead = orig->next;
    struct Node* l1 = orig , *l2 = orig->next;
    while (l1 && l2){
        l1->next = l1->next->next;
        if (l2->next)
            l2->next = l2->next->next;
        l1 = l1->next;
        l2 = l2->next;
    }

    return newHead;

    
}