https://leetcode.com/problems/remove-linked-list-elements/description/

```C
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    while (head && head->val == val) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
    
    if (head == NULL) {
        return NULL;
    }
    
    struct ListNode* current = head;
    while (current->next) {
        if (current->next->val == val) {
            struct ListNode* temp = current->next;
            current->next = temp->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
    
    return head;
}
```