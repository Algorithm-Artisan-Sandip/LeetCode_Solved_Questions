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
    TreeNode* findMaxInLeft(TreeNode* root) {
        while(root->right != NULL) root = root->right;
        return root;
    }
    TreeNode* findAndDelete(TreeNode* root, int target) {
        if(root == NULL) return NULL;
        
        if(root->val == target) {
            if(root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }
            else if(root->left != NULL && root->right == NULL) {
                TreeNode* childSubtree = root->left;
                delete root;
                return childSubtree;
            }
            else if(root->left == NULL && root->right != NULL) {
                TreeNode* childSubtree = root->right;
                delete root;
                return childSubtree;
            }
            else {
                TreeNode* maxInLeft = findMaxInLeft(root->left);
                root->val = maxInLeft->val;
                root->left = findAndDelete(root->left, maxInLeft->val);
                return root;
            }
        }
        else if(root->val > target) {
            root->left = findAndDelete(root->left, target);
        }
        else if(root->val < target) {
            root->right = findAndDelete(root->right, target);
        }

        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        return findAndDelete(root, key);
    }
};