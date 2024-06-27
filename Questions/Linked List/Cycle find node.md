https://leetcode.com/problems/linked-list-cycle-ii/description/

```C
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode** nodes = NULL;
    int count = 0;
    while (head) {
        for (int i = 0; i < count; i++) {
            if (head == nodes[i]) {
                free(nodes);
                return head;
            }
        }
        nodes = realloc(nodes, (count + 1) * sizeof(struct ListNode*));
        nodes[count] = head;
        head = head->next;
        count++;
    }
    free(nodes);
    return NULL;
}
```