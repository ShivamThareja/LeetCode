https://leetcode.com/problems/valid-parentheses/

```C
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char val;
    struct Node* next;
} NODE;

// Global variable head
NODE* head = NULL; // Stack is empty

int isEmpty() { return head == NULL; }

NODE* createNode(char val) {
    NODE* newNode = malloc(sizeof(NODE));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void push(char val) {
    NODE* newNode = createNode(val);
    if (isEmpty()) {
        head = newNode;
        return;
    }
    // 3 2 1
    // push 4
    newNode->next = head;
    head = newNode;
    // 4 3 2 1
}

char pop() {
    if (isEmpty()) {
        printf("Stack Underflow...\n");
        return -1;
    }
    // 3 2 1
    // 2 1
    NODE* tmp = head;
    char val = tmp->val;
    head = head->next;
    free(tmp);
    return val;
}

char peek() {
    if (isEmpty()) {
        printf("Stack Underflow...\n");
        return -1;
    }
    return head->val;
}

void display() {
    if (isEmpty()) {
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

void destroyList() {
    NODE* tmp;
    while (head != NULL) {
        tmp = head->next;
        free(head);
        head = tmp;
    }
}

bool isValid(char* s) {
    char c;
    bool v = true;
    head = NULL;
    for (int i = 0; (c = s[i]) != '\0'; i++) {

        if (c == '(' || c == '{' || c == '[') {
            push(c);
        } else {
            if ((c == ')' && peek() == '(') || (c == ']' && peek() == '[') ||
                (c == '}' && peek() == '{')) {
                pop();
            } else {
                return false;
            }
        }
    }
    if (!isEmpty())
        v = false;
    return v;
}
```