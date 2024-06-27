https://leetcode.com/problems/middle-of-the-linked-list/

```C
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* tmp = head;
    int size = 0;
    while (tmp) {
        tmp = tmp->next;
        size++;
    }
    int mid = (size / 2) + 1;
    tmp = head;
    for (int i = 1; i < mid; i++) {
        tmp = tmp->next;
    }
    return tmp;
}
```