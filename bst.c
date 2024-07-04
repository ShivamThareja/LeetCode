#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int val;
  struct node *left;
  struct node *right;
} NODE;

NODE *createNode(int ele) {
  NODE *newNode = malloc(sizeof(NODE));
  newNode->val = ele;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

NODE *insert(NODE *root, int ele) {
  NODE *newNode = createNode(ele);
  root = root ? root : newNode; // Root is newNode if root is NULL

  NODE *tmp = root;
  NODE *parent = NULL;

  while (tmp != NULL) {
    parent = tmp;
    tmp = ele < tmp->val ? tmp->left : tmp->right;
  }

  if (ele < parent->val) {
    parent->left = newNode;
  } else if (ele > parent->val) {
    parent->right = newNode;
  }

  return root;
}

NODE *delete(NODE *root, int target) {
  NODE *tmp = root;
  NODE *parent = NULL;

  while (tmp->val != target) {
    parent = tmp;
    if (target < tmp->val) {
      tmp = tmp->left;
    } else if (target > tmp->val) {
      tmp = tmp->right;
    }
  }

  // NODE to be deleted can have 0, 1 or 2 children.

  // 0
  int children = 0;
  if (tmp->left)
    children++;
  if (tmp->right)
    children++;

  if (children == 0) {
    if (parent->left == tmp)
      parent->left = NULL;
    else
      parent->right = NULL;
    free(tmp);
  }

  // 1
  if (children == 1) {
    NODE *child;
    if (tmp->left != NULL) {
      child = tmp->left;
    } else {
      child = tmp->right;
    }

    if (parent->left == tmp) {
      parent->left = child;
    } else {
      parent->right = child;
    }

    // 2
    if (children == 2) {
    }
  }
}

void inorder(NODE *root) {
  if (!root)
    return;

  inorder(root->left);
  printf("%d ", root->val);
  inorder(root->right);
}

void destroyTree(NODE *root) {
  if (!root)
    return;
  NODE *leftTree = root->left;
  NODE *rightTree = root->right;
  free(root);
  destroyTree(leftTree);
  destroyTree(rightTree);
}

int main(void) {
  NODE *root = NULL;

  root = insert(root, 4);
  root = insert(root, 6);
  root = insert(root, 3);
  root = insert(root, 8);
  root = insert(root, 1);
  root = insert(root, 9);
  root = insert(root, 0);
  root = insert(root, 11);
  root = insert(root, 2);
  root = insert(root, 10);
  root = insert(root, -2);

  inorder(root);
}
