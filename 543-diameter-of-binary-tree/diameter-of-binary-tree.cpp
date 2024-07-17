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
    int height(TreeNode* node) {
        if(node == NULL) return 0;

        int leftSubtreeHeight = height(node->left);
        int rightSubtreeHeight = height(node->right);
        int totalHeight = max(leftSubtreeHeight, rightSubtreeHeight) + 1;

        return totalHeight;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }

        int leftSubtreeDiameter = diameterOfBinaryTree(root->left);
        int rightSubtreeDiameter = diameterOfBinaryTree(root->right);

        int leftPlusRightSubtreeDiameter = height(root->left) + height(root->right);

        int ans = max(leftPlusRightSubtreeDiameter, max(leftSubtreeDiameter, rightSubtreeDiameter));

        return ans;
    }
};