https://leetcode.com/problems/swap-nodes-in-pairs/

```C
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if (!head || !head->next)
        return head;
    struct ListNode* dummyNode = malloc(sizeof(struct ListNode));
    dummyNode->next = head;

    struct ListNode* prevNode = dummyNode;
    struct ListNode* currNode = head;

    while (currNode && currNode->next) {
        prevNode->next = currNode->next;
        currNode->next = prevNode->next->next;
        prevNode->next->next = currNode;

        prevNode = currNode;
        currNode = currNode->next;
    }

    return dummyNode->next;
}
```

Dummy node created when we need to keep track of a previous node...