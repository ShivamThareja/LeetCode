
```C
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool cmp(struct TreeNode* p1, struct TreeNode* p2) {
    // If both reach NULL together, the paths are same, but stop the traversal
    // thru this path since NULL reached
    if (p1 == NULL && p2 == NULL)
        return true;
    // If one of them is NULL and other is not, then they are not same, both
    // null condition handled earlier thats why we can use ||
    if (p1 == NULL || p2 == NULL)
        return false;

    // End condition, if not equal, false is the answe.
    if (p1->val != p2->val) {
        return false;
    }

    // Traverse thru p1 and p2 oppositely since we wanna check mirror image
    // We have if condition here since if further recursion resulsts in a false,
    // and in current recursion both values are same, the answer should not be
    // set to true now, since it was already declared false.
    if (!cmp(p1->left, p2->right))
        return false;
    if (!cmp(p1->right, p2->left))
        return false;
    return true;
}

bool isSymmetric(struct TreeNode* root) { return cmp(root->left, root->right); }
```