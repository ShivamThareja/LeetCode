https://leetcode.com/problems/remove-nth-node-from-end-of-list/

Obvious way


2 pointer approach
```C
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if(head == NULL || head -> next == NULL) return NULL;

    struct ListNode* p1 = head;
    struct ListNode* p2 = head;

    for(int i = 0; i < n; i++){
        p2 = p2 -> next;
    }

    if(p2 == NULL){
        return head -> next;
    } else {
        p2 = p2 -> next;
    }

    while(p2 != NULL){
        p1 = p1 -> next;
        p2 = p2 -> next;
    }

    struct ListNode* tmp = p1 -> next;
    p1 -> next = tmp -> next;
    free(tmp);
    return head;
}
```
This is done without counting the total number of nodes.
We move one pointer such that when the aage ka pointer reaches NULL, the pehle ka pointer reaches the node before the node to be deleted.

THE DISTANCE b/w two nodes.
