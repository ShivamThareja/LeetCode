https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/

Without stacks
```C
int minAddToMakeValid(char* s) {
    int count = 0;
    int ans = 0;
    char c;
    for(int i = 0; (c = s[i]) != '\0'; i++){
        if(c == '(') count++;
        if(c == ')') count--;

        if(count < 0){
            ans += abs(count);
            count = 0;
        }
    }
    ans = count > 0 ? ans + count : ans;
    return ans;
}
```
The logic is as soon as the count of ) exceeds count of (, there is no way the extra ) is gonna get nullified, so add count. But when we have extra (, there is a possibility to nullify them if there are future ), therefore, we handle extra ) while in loop, and extra ( when the loop is finished.


With stacks
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

int minAddToMakeValid(char* s) {
    char c;
    head = NULL;
    int a = 0;
    for (int i = 0; (c = s[i]) != '\0'; i++) {
        if (c == '(' || c == '{' || c == '[') {
            push(c);
        }
        else if ((c == ')' && peek() == '(') || (c == ']' && peek() == '[') ||
            (c == '}' && peek() == '{')) {
            pop();
        } else {
            push(c);
        }
    }
    while (head != NULL) {
        a++;
        head = head->next;
    }
    destroyList();
    return a;
}
```