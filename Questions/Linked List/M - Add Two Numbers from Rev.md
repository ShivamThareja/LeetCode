https://leetcode.com/problems/add-two-numbers

```C
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* sum = NULL;
    struct ListNode* tmp = NULL;
    int carry = 0, value;

    while (l1 || l2 || carry) {
        if (!sum) {
            sum = malloc(sizeof(struct ListNode));
            tmp = sum;
        } else {
            tmp->next = malloc(sizeof(struct ListNode));
            tmp = tmp->next;
        }
        tmp->next = NULL;

        value = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);

        tmp->val = value % 10;
        carry = value / 10;

        l1 = l1 ? l1->next : NULL;
        l2 = l2 ? l2->next : NULL;
    }

    return sum;
}
```