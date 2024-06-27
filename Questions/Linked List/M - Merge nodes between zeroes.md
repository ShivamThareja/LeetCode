https://leetcode.com/problems/merge-nodes-in-between-zeros/

Kinda complex, better way below...
```C
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeNodes(struct ListNode* head) {
    struct ListNode* tmp = head->next;
    struct ListNode* z = head;
    int sum = 0;
    
    while (tmp) {
        if (tmp->val == 0) {
            z->val = sum;
            if (tmp->next) {
                z->next = tmp;
                z = tmp;
            } else {
                z->next = NULL;
            }
            sum = 0;
        } else {
            sum += tmp->val;
        }
        tmp = tmp->next;
    }
    
    return head;
}
```

Another way
Start traversing, while next node is not zero, delete the next zero and store sum, when zero encountered, put the value of the sum and move to the new 0 node encountered.