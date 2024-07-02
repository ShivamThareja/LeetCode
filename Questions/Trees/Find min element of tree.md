```C
int min(NODE *root) {
  if (root == NULL) {
    return 9999999;
  }
  int val = root->val;
  int rightmin = min(root->right);
  int leftmin = min(root->left);
  int min = leftmin < rightmin ? leftmin : rightmin;
  return val < min ? val : min;
}
```