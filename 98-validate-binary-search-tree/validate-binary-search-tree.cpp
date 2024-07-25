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
    bool validateBST(TreeNode* root, long long int lb, long long int ub) {
        if(root == NULL) return true;

        bool cond1 = (root->val > lb);
        bool cond2 = (root->val < ub);
        bool leftAns = validateBST(root->left, lb, root->val);
        bool rightAns = validateBST(root->right, root->val, ub);

        if(cond1 && cond2 && leftAns && rightAns) {
            return true;
        }
        else {
            return false;
        }
    }
    bool isValidBST(TreeNode* root) {
        long long int lowerBound = -2147483657;
        long long int upperBound = 2147483657;
        return validateBST(root, lowerBound, upperBound);
    }
};