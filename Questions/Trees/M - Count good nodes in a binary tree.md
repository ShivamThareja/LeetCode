https://leetcode.com/problems/count-good-nodes-in-binary-tree/
```C
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void traverse(struct TreeNode* root, int max, int* gns) {
    if (!root)
        return;
    if (root->val >= max) {
        *gns += 1;
    }
    max = max > root->val ? max : root->val;
    traverse(root->left, max, gns);
    traverse(root->right, max, gns);
}

int goodNodes(struct TreeNode* root) {
    int gns = 0;
    traverse(root, root->val, &gns);
    return gns;
}
```