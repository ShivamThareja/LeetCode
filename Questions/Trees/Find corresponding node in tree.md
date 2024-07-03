https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/
```C
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode* preorder(struct TreeNode* p1, struct TreeNode* p2,
                          struct TreeNode* target) {
    if (p1 == target)
        return p2; // END condition, stop when target found
    if (p1 == NULL)
        return NULL; // While traversing, if end of path reached return NULL

    // doing preorder
    struct TreeNode* left = preorder(p1->left, p2->left, target);
    struct TreeNode* right = preorder(p1->right, p2->right, target);

    // recursion
    if (left)
        return left;
    if (right)
        return right;
    return NULL;
}

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned,
                            TreeNode* target) {
        return preorder(original, cloned, target);
    }
};
```