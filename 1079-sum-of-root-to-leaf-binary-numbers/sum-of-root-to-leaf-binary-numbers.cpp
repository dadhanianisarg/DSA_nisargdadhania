class Solution {
    int helper(TreeNode* node, int current) {
        if (node == NULL) return 0;
        current = current * 2 + node->val;
        if (node->left == NULL && node->right == NULL)
            return current;

        return helper(node->left, current) + helper(node->right, current);
    }

public:
    int sumRootToLeaf(TreeNode* root) {
        return helper(root, 0);
    }
};