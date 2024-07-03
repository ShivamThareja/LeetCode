```C
int min(NODE *root) {
  if (root == NULL) {
    return 9999999;
  }
  int rightmin = root->val;
  int leftmin = root->val;
  int rootval = root->val;
  if(root->right != NULL){
	  rightmin = min(root->right);
  }
  if(root->left != NULL){
	  leftmin = min(root->left);
  }
  int min = leftmin < rightmin ? leftmin : rightmin;
  return rootval < min ? rootval : min;
}
```