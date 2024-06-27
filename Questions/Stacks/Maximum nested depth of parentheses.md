https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/

```C
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

int maxDepth(char* s) {
    int level = 0;
    int mlevel = 0;
    char c;
    head = NULL;

    for (int i = 0; (c = s[i]) != '\0'; i++) {
        if (c == '(' || c == '{' || c == '[') {
            push(c);
            level++;
            mlevel = (level > mlevel) ? level : mlevel;
        } else if (c == ')' || c == '}' || c == ']') {
            if ((c == ')' && peek() == '(') || (c == ']' && peek() == '[') ||
                (c == '}' && peek() == '{')) {
                pop();
                level--;
            }
        }
    }
    
    destroyList();
    return mlevel;
}
```

If no stacks...
```C
int maxDepth(char* s) {
    int level = 0;
    int mlevel = 0;
    for(int i = 0; i < strlen(s) - 1; i++){
        if(s[i] == '('){
            level++;
        }
        if(s[i] == ')'){
            level--;
        }
        mlevel = mlevel < level ? level : mlevel;
    }
    return mlevel;
}
```