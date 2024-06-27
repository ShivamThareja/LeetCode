https://leetcode.com/problems/merge-in-between-linked-lists/description/

```C
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b,
                                struct ListNode* list2) {
    struct ListNode* bfrA = list1;
    struct ListNode* afrB = list1;

    for (int i = 1; i < a; i++) {
        bfrA = bfrA->next;
        afrB = afrB->next;
    }
    for (int i = 0; i < (b - a) + 2; i++) {
        afrB = afrB->next;
    }

    bfrA->next = list2;
    struct ListNode* tmp = list2;
    while (tmp->next) {
        tmp = tmp->next;
    }
    tmp->next = afrB;

    return list1;
}
```