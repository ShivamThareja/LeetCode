https://leetcode.com/problems/odd-even-linked-list/description/

```C
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    if (head == NULL || head->next == NULL || head->next->next == NULL) {
        return head;
    }

    struct ListNode* oddHead = head;
    struct ListNode* evenHead = head->next;
    struct ListNode* tmp = evenHead;
    while (oddHead != NULL && evenHead != NULL && evenHead->next != NULL &&
           oddHead->next != NULL) {
        oddHead->next = oddHead->next->next;
        oddHead = oddHead->next;

        evenHead->next = evenHead->next->next;
        evenHead = evenHead->next;
    }

    oddHead->next = tmp;
    return head;
}
```