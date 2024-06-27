https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/

```C
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int findgcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

struct ListNode* insertNode(struct ListNode* node, int val){
    struct ListNode* newNode = malloc(sizeof(struct ListNode));
    newNode->val = val;

    struct ListNode* tmp = node -> next;
    node -> next = newNode;
    newNode->next = tmp;

    return newNode;
}

struct ListNode* insertGreatestCommonDivisors(struct ListNode* head){
    struct ListNode* tmp = head;
    int cur, nxt, gcd;
    while(tmp -> next){
        int cur = tmp->val;
        int nxt = tmp->next->val;

        int gcd = findgcd(cur, nxt);

        tmp = insertNode(tmp, gcd);

        tmp = tmp -> next;
    }
    return head;
}
```