```C
int heightTree(NODE *root) {
  if (root == NULL) {
    return 0;
  }

  int leftHeight = heightTree(root->left);
  int rightHeight = heightTree(root->right);

  return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}
```
