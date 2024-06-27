https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/

```C
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int getDecimalValue(struct ListNode* head) {
    struct ListNode* tmp = head;
    int size = 0;
    while (tmp) {
        tmp = tmp->next;
        size++;
    }
    tmp = head;
    int num = 0;
    for (int i = 1; i <= size; i++) {
        num += (tmp->val) * (pow(2, size - i));
        tmp = tmp->next;
    }
    return num;
}
```

Do in just 1 loop
```C
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int getDecimalValue(struct ListNode* head) {
    struct ListNode* tmp = head;
    int num = 0;
    while (tmp) {
        num = num*2 + tmp->val;
        tmp = tmp -> next;
    }
    return num;
}
```