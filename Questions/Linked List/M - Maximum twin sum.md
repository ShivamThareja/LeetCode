https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description/

```C
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* revList(struct ListNode* head) {
    struct ListNode* newList = NULL;
    struct ListNode* newHead = head;
    while (newHead) {
        newHead = head->next;
        head->next = newList;
        newList = head;
        head = newHead;
    }
    return newList;
}

int pairSum(struct ListNode* head) {
    int max = 0;
    if (!(head->next->next)) {
        max += head->val + head->next->val;
        return max;
    }
    struct ListNode* temp = head->next;
    struct ListNode* mid = head;
    while (temp->next) {
        mid = mid->next;
        temp = temp->next->next;
    }
    mid = mid->next;

    struct ListNode* twinList = revList(mid);

    while (twinList) {
        max = (head->val + twinList->val) > max ? (head->val + twinList->val)
                                                : max;
        twinList = twinList->next;
        head = head->next;
    }
    return max;
}
```