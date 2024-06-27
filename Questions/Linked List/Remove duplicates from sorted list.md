https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
```C
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* tmp = head;
    struct ListNode* prev = NULL;
    int pVal = 101;
    while(tmp){
        if(tmp -> val == pVal){
            prev->next = tmp->next;
            free(tmp);
            tmp = prev->next;
            continue;
        }
        prev = tmp;
        pVal = tmp -> val;
        tmp = tmp->next;
    }
    return head;
}
```