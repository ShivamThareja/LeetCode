https://leetcode.com/problems/remove-nodes-from-linked-list/description/

```C
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct Node {
    int val;
    struct Node* next;
} NODE;

int isEmpty(NODE* head) { return head == NULL; }

NODE* createNode(int val) {
    NODE* newNode = malloc(sizeof(NODE));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

NODE* push(NODE* head, int val) {
    NODE* newNode = createNode(val);
    newNode->next = head;
    return newNode;
}

NODE* pop(NODE* head) {
    if (isEmpty(head)) {
        printf("Stack Underflow...\n");
        return head;
    }
    NODE* tmp = head;
    head = head->next;
    int val = tmp->val;
    free(tmp);
    return head;
}

int peek(NODE* head) {
    if (isEmpty(head)) {
        printf("Stack Underflow...\n");
        return -1;
    }
    return head->val;
}

void display(NODE* head) {
    if (isEmpty(head)) {
        printf("Stack Empty\n");
        return;
    }
    NODE* tmp = head;
    while (tmp != NULL) {
        printf("%d ", tmp->val);
        tmp = tmp->next;
    }
    printf("\n");
}

NODE* destroyList(NODE* head) {
    NODE* tmp;
    while (head != NULL) {
        tmp = head->next;
        free(head);
        head = tmp;
    }
    return NULL;
}

struct ListNode* removeNodes(struct ListNode* head) {
    struct ListNode* tmp = head;
    NODE* stack1 = NULL;
    while (tmp != NULL) {
        stack1 = push(stack1, tmp->val);
        tmp = tmp->next;
    }

    NODE* stack2 = NULL;

    int max = peek(stack1);
    int num;
    while (!isEmpty(stack1)) {
        num = stack1->val;
        max = stack1->val > max ? stack1->val : max;

        stack1 = (pop(stack1));
        if (num >= max) {
            stack2 = push(stack2, num);
        }
    }
    return stack2;
}
```