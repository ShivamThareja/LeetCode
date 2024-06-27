https://leetcode.com/problems/palindrome-linked-list/

```C
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* temp = head;
    struct ListNode* next;
    while (temp) {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    return prev;
}

bool isPalindrome(struct ListNode* head) {
    struct ListNode* tmp = head;
    int size = 0;
    while (tmp) {
        tmp = tmp->next;
        size++;
    }
    tmp = head;

    struct ListNode* mid = head;
    for (int i = 1; i <= ((size % 2 == 1) ? (size / 2 + 1) : (size / 2)); i++) {
        mid = mid->next;
    }

    mid = reverseList(mid);
    bool isP = true;
    for (int i = 1; i <= size / 2; i++) {
        if (tmp->val != mid->val) {
            isP = false;
        }
        tmp = tmp->next;
        mid = mid->next;
    }

    return isP;
}
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* temp = head;
    struct ListNode* next;
    while (temp) {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    return prev;
}

bool isPalindrome(struct ListNode* head) {
    struct ListNode* tmp = head;
    int size = 0;
    while (tmp) {
        tmp = tmp->next;
        size++;
    }
    tmp = head;

    struct ListNode* mid = head;
    for (int i = 1; i <= ((size % 2 == 1) ? (size / 2 + 1) : (size / 2)); i++) {
        mid = mid->next;
    }

    mid = reverseList(mid);
    bool isP = true;
    for (int i = 1; i < size / 2; i++) {
        if (tmp->val != mid->val) {
            isP = false;
        }
        tmp = tmp->next;
        mid = mid->next;
    }

    return isP;
}
```