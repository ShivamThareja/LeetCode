https://leetcode.com/problems/add-two-numbers-ii/

Copy pasta
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
        p2 = p2->next;
        temp->next = p1;
        p1 = temp;
    }
    return p1;
}
struct ListNode* addRev(struct ListNode* l1, struct ListNode* l2) {
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

        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2;
    }

    return sum;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    return reverseList(addRev(reverseList(l1), reverseList(l2)));
}
```