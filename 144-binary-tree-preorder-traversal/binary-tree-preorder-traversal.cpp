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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorderHelper(root,ans);
        return ans;
    }
private:
    void preorderHelper(TreeNode* root, vector<int>& ans) {
        if(root == NULL) {
            return;
        }

        // Node :
        ans.push_back(root->val);
        // Left :
        preorderHelper(root->left, ans);
        // Right :
        preorderHelper(root->right, ans);
    }
};