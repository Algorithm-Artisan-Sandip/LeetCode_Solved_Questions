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
    int findTarget(TreeNode* root, int& k) {
        if(root == NULL) return -1; // if not found then return -1.
        int leftAns = findTarget(root->left, k);  // find in left part
        if(leftAns != -1) return leftAns;  // if left part answer found then return
        k--;  // decrement k each time
        if(k == 0) return root->val;  // if k becomes zero then the node's data is our desired value.
        return findTarget(root->right, k); // find and return answer in right part.
    }

    int kthSmallest(TreeNode* root, int k) {
        return findTarget(root, k);
    }
};