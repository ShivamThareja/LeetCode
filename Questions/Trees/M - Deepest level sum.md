https://leetcode.com/problems/deepest-leaves-sum/description/
```C
int height(struct TreeNode* root, int lvl, int* maxlvl){
    if(root == NULL){
        return 0;
    }
    *maxlvl = *maxlvl > lvl ? *maxlvl : lvl;
    height(root->left, lvl + 1, maxlvl);
    height(root->right, lvl + 1, maxlvl);
    return *maxlvl;
}

void preordersum(struct TreeNode* root, int lvl, int maxlvl, int* sum){
    if(root == NULL){
        return;
    }
    if(lvl == maxlvl){
        *sum += root->val;
    }
    preordersum(root->left, lvl + 1, maxlvl, sum);
    preordersum(root->right, lvl + 1, maxlvl, sum);
}

int deepestLeavesSum(struct TreeNode* root) {
    int maxlvl = 0;
    height(root, 0, &maxlvl);
    int sum = 0;
    preordersum(root, 0, maxlvl, &sum);
    return sum;
}
```