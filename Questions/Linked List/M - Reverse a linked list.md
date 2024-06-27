https://leetcode.com/problems/reverse-linked-list/

```C
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* p1 = NULL;
    struct ListNode* p2 = head;
    while (p2) {
        struct ListNode* temp = p2;
        p2 = p2 -> next;
        temp -> next = p1;
        p1 = temp;
    }
    return p1;
}
```

p1 is our newly created reverse list
p2 is our current list.
we will point temp to the head of our currect list (p2) again and again.
we will move p2 to the 2nd node of our current list.
we will take out temp (which was pointing to the first element of current list) from the current list and point its next to the reverse list's head p1 and we will update temp to be the new p1's head.

We are basically creating a new list, taking out elements one by one from the current list while preserving the remaining part of our current list.