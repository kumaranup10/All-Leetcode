/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, int minVal, long long &secondMin) {
        if (!root)
            return;

        if (root->val > minVal && root->val < secondMin)
            secondMin = root->val;

        dfs(root->left, minVal, secondMin);
        dfs(root->right, minVal, secondMin);
    }

    int findSecondMinimumValue(TreeNode* root) {
        if (!root)
            return -1;

        long long secondMin = LLONG_MAX;
        int minVal = root->val;

        dfs(root, minVal, secondMin);

        return (secondMin == LLONG_MAX) ? -1 : secondMin;
    }
};