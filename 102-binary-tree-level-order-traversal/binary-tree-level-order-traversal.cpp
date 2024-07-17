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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        levelOrderHelper(root, ans);
        return ans;
    }
private:
    void levelOrderHelper(TreeNode* root, vector<vector<int>>& ans) {
        if(root == NULL) return;
        queue<TreeNode*> q;

        q.push(root);
        q.push(NULL);  // marker

        vector<int> currLevel;
        while(!q.empty()) {
            TreeNode* currNode = q.front();
            q.pop();

            if(currNode == NULL) {
                ans.push_back(currLevel);
                currLevel.clear();
                if(!q.empty()) q.push(NULL);
            }

            else {
                currLevel.push_back(currNode->val);

                // push left node :
                if(currNode->left != NULL) {
                    q.push(currNode->left);
                }
                // push right node :
                if(currNode->right != NULL) {
                    q.push(currNode->right);
                }
            }
        }
    }
};