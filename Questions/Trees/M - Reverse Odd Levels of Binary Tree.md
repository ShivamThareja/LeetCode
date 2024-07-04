https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/
```C
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void swap(struct TreeNode* r1, struct TreeNode* r2) {
    int tmp = r1->val;
    r1->val = r2->val;
    r2->val = tmp;
}

void preorder(struct TreeNode* r1, struct TreeNode* r2, int lvl) {
    if (r1 == NULL) {
        return;
    }
    if (lvl % 2 == 0) {
        swap(r1, r2);
    }

    // Maintain two pointers, one to left and one to right. If you go left in r1
    // and right in r2, then you are at the leftmost and rightmost node of these
    // two nodes. Swap.
    preorder(r1->left, r2->right, lvl + 1);
    preorder(r1->right, r2->left, lvl + 1);
}

struct TreeNode* reverseOddLevels(struct TreeNode* root) {
    preorder(root->left, root->right, 0);
    return root;
}
```