https://leetcode.com/problems/intersection-of-two-linked-lists/

TRICK
```C
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* getIntersectionNode(struct ListNode* headA,
                                     struct ListNode* headB) {
    struct ListNode* tmpA = headA;
    struct ListNode* tmpB = headB;
    while (tmpA) {
        tmpA->val *= -1;
        tmpA = tmpA->next;
    }
    tmpA = headA;

    int i;
    for(i = 0; tmpB; i++){
        if ((tmpB->val) < 0) {
            break;
        }
        tmpB = tmpB ->next;
    }
    while (tmpA) {
        tmpA->val *= -1;
        tmpA = tmpA->next;
    }

    tmpB = headB;
    for(int j = 0; j < i; j++){
        tmpB = tmpB->next;
    }
    return tmpB;
}
```


ONE MORE WAY
Find length of list A, find length of list B.
Find difference, whichever is larger, move its pointer ahead by the difference, that means now both their pointers are at the same distance from the intersection.
:)

SMARTASS but not the best solution...
```C
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    if (!headA || !headB) {
        return NULL;
    }
    struct ListNode* h1 = headA;
    struct ListNode* h2 = headB;
    while (h1 != h2) {
        h1 = h1 == NULL ? headB : h1->next;
        h2 = h2 == NULL ? headA : h2->next;
    }
    return h1;
}
```
![[Pasted image 20240624142736.png]]