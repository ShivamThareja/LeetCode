https://leetcode.com/problems/linked-list-in-binary-tree/
```C
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool traverse(struct ListNode* head, struct TreeNode* root) {
    if (!head)
        return true;
    if (!root)
        return false;

    if (root->val == head->val) {
        if (traverse(head->next, root->left) ||
            traverse(head->next, root->right)) {
            return true;
        }
    }

    return traverse(head, root->left) || traverse(head, root->right);
}

bool isSubPath(struct ListNode* head, struct TreeNode* root) {
    return traverse(head, root);
}
```