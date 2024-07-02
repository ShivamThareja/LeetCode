```C
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  int val;
  struct node *left;
  struct node *right;
} NODE;

// QUEUE
typedef struct queue {
  NODE *node;
  struct queue *next;
} QUEUE;

QUEUE *createQNode(NODE *node) {
  QUEUE *newNode = malloc(sizeof(QUEUE));
  newNode->next = NULL;
  newNode->node = node;
  return newNode;
}

int isEmpty(QUEUE *head) { return head == NULL; }

void enqueue(QUEUE **head, QUEUE **tail, NODE *node) {
  if (node == NULL)
    return;
  QUEUE *tmp = createQNode(node);
  if (*head == NULL) {
    *head = *tail = tmp;
  } else {
    (*tail)->next = tmp;
    *tail = tmp;
  }
}

NODE *dequeue(QUEUE **head, QUEUE **tail) {
  if (isEmpty(*head)) {
    printf("Queue Underflow\n");
    return NULL;
  }
  QUEUE *tmp = *head;
  NODE *node = tmp->node;
  *head = (*head)->next;
  if (*head == NULL) {
    *tail = NULL;
  }
  free(tmp);
  return node;
}

void display(QUEUE *head) {
  QUEUE *tmp = head;
  printf("Queue: ");
  while (tmp != NULL) {
    printf("%d ", tmp->node->val);
    tmp = tmp->next;
  }
  printf("\n");
}

int peek(QUEUE *head) { return head ? head->node->val : -1; }
// QUEUE

NODE *createNode(int val) {
  NODE *newNode = malloc(sizeof(NODE));
  newNode->val = val;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

void levelorder(NODE *root) {
  if (root == NULL)
    return;
  QUEUE *head = NULL;
  QUEUE *tail = NULL;
  enqueue(&head, &tail, root);
  while (!isEmpty(head)) {
    NODE *tmp = dequeue(&head, &tail);
    if (tmp != NULL) {
      printf("%d ", tmp->val);
      enqueue(&head, &tail, tmp->left);
      enqueue(&head, &tail, tmp->right);
    }
  }
}

NODE *createTreeFromArray(int arr[], int size) {
  if (size == 0)
    return NULL;

  QUEUE *head = NULL, *tail = NULL;
  NODE *root = createNode(arr[0]);
  enqueue(&head, &tail, root);

  int i = 1;
  while (!isEmpty(head) && i < size) {
    NODE *current = dequeue(&head, &tail);

    if (i < size) {
      current->left = createNode(arr[i++]);
      enqueue(&head, &tail, current->left);
    }

    if (i < size) {
      current->right = createNode(arr[i++]);
      enqueue(&head, &tail, current->right);
    }
  }

  return root;
}

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
  int size = sizeof(arr) / sizeof(arr[0]);

  NODE *root = createTreeFromArray(arr, size);

  printf("levelorder\n");
  levelorder(root);
  printf("\n");
}
```