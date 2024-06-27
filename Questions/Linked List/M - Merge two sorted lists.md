https://leetcode.com/problems/merge-two-sorted-lists

```C
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (!list1) return list2;
    if (!list2) return list1;

    struct ListNode* tmp1 = (list1->val < list2->val) ? list1 : list2;
    struct ListNode* tmp2 = (list1->val < list2->val) ? list2 : list1;
    struct ListNode* head = tmp1;
    struct ListNode* tmp;

    while (tmp1->next && tmp2) {
        if (tmp2->val < tmp1->next->val) {
            tmp = tmp2->next;
            tmp2->next = tmp1->next;
            tmp1->next = tmp2;
            tmp2 = tmp;
        } else {
            tmp1 = tmp1->next;
        }
    }

    if (tmp2) {
        tmp1->next = tmp2;
    }

    return head;
}
```

Make whatever the smaller value list is as the tmp1 and add now update the tmp1 by declaring it as the main head and head will be the answer.