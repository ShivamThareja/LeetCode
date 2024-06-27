https://leetcode.com/problems/linked-list-cycle/description/

Bad way
```C
bool hasCycle(struct ListNode *head) {
    struct ListNode** nodes = NULL;
    int count = 0;
    while(head) {
        for(int i = 0; i < count; i++) {
            if(head == nodes[i]) {
                free(nodes);
                return true;
            }
        }
        nodes = realloc(nodes, (count + 1) * sizeof(struct ListNode*));
        nodes[count] = head;
        head = head->next;
        count++;
    }
    free(nodes);
    return false;
}
```

Fast and Slow
```C
bool hasCycle(struct ListNode *head) {
    if (!head || !(head->next)) {
        return false;
    }

    struct ListNode* p1 = head;
    struct ListNode* p2 = head->next;

    while (p1 != p2) {
        if (p2 == NULL || p2->next == NULL) {
            return false;
        }
        p1 = p1->next;
        p2 = p2->next->next;
    }
    return true;
}
```