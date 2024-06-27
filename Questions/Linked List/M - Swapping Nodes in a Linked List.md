https://leetcode.com/problems/swapping-nodes-in-a-linked-list/description/

```C
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapNodes(struct ListNode* head, int k) {
    struct ListNode* tmp = head;
    int n = 0;
    while(tmp){
        n++;
        tmp = tmp -> next;
    }

    struct ListNode* one = head;
    struct ListNode* two = head;
    for(int i = 1; i < k; i++){
        one = one -> next;
    }
    for(int i = 1; i < n - k + 1; i++){
        two = two -> next;
    }

    int temp;
    temp = one -> val;
    one -> val = two -> val;
    two -> val = temp;

    return head;
}
```