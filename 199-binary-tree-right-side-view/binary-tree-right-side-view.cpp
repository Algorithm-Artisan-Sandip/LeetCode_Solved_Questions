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
    void findRightView(TreeNode* root, vector<int>& ans, int level, int& size) {
        if(root == NULL) return;

        if(level == size) {
            ans.push_back(root->val);
            size++;
        }

        findRightView(root->right, ans, level+1, size);
        findRightView(root->left, ans, level+1, size);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        int size = 0;
        findRightView(root, ans, 0, size);
        return ans;
    }
};