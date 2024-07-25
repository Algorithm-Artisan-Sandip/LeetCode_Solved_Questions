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
    void createInorder(TreeNode* root, vector<int>& inOrder) {
        if(root == NULL) return;

        createInorder(root->left, inOrder);
        inOrder.push_back(root->val);
        createInorder(root->right, inOrder);
    }

    bool findPair(vector<int> inOrder, int k) {
        int i = 0, j = inOrder.size()-1;
        while(i<j) {
            if(inOrder[i] + inOrder[j] == k) return true;
            else if(inOrder[i] + inOrder[j] > k) j--;
            else i++;
        }
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> inOrder;
        createInorder(root, inOrder);
        return findPair(inOrder, k);
    }
};