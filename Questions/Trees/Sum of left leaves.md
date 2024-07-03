https://leetcode.com/problems/sum-of-left-leaves/
```C
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void preorder(struct TreeNode* root, struct TreeNode* parent, int* ans){
    if(!root) return; // If end of a path encountered.
    // Checking for left leaf, parent is maintained to check left
    if(!root->left && !root->right && parent->left == root){
        *ans += root->val;
    }
    // New root is root->left and root->right, 2 baby processes
    preorder(root->left, root, ans);
    preorder(root->right, root, ans);
}

int sumOfLeftLeaves(struct TreeNode* root) {
    // If initially one node only present in tree
    if(!root->left && !root->right){
        return 0;
    }
    int ans = 0;
    // Passing by ref and updating ans value in preorderfunction itself
    preorder(root, NULL, &ans);
    return ans;
}
```