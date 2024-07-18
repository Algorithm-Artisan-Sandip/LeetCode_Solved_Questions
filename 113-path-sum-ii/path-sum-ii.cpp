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
    void findAllPaths(TreeNode* root, int targetSum, int sum, vector<int> singlePath, vector<vector<int>>& totalPaths) {
        if(root == NULL) return;
        sum += root->val;
        singlePath.push_back(root->val);
        if(root->left == NULL && root->right == NULL) {
            if(sum == targetSum) {
                totalPaths.push_back(singlePath);
            }
        }

        findAllPaths(root->left, targetSum, sum, singlePath, totalPaths);
        findAllPaths(root->right, targetSum, sum, singlePath, totalPaths);
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> singlePath;
        vector<vector<int>> totalPaths;
        int sum = 0;
        findAllPaths(root, targetSum, sum, singlePath, totalPaths);
        return totalPaths;
    }
};