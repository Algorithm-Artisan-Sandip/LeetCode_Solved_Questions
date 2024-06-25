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
    // Helper method to perform the in-place transformation to GST.
    // It updates each node's value with the sum of all values greater than or equal to it.
    void GetSum(int &Experience, TreeNode* root) {
        // Base case: If the node is null, simply return.
        if (root == nullptr) return;

        // Recursively traverse the right subtree first (to handle larger values first).
        GetSum(Experience, root->right);

        // Update the current node's value by adding the current accumulated parent sum.
        Experience += root->val;
        root->val = Experience;

        // Recursively traverse the left subtree.
        GetSum(Experience, root->left);
    }

    // Main method to initiate the transformation from BST to GST.
    TreeNode* bstToGst(TreeNode* root) {
        // Initialize the starting sum to 0.
        int startSum = 0;

        // Call the helper method to update the tree.
        GetSum(startSum, root);

        // Return the root of the modified tree.
        return root;
    }
};