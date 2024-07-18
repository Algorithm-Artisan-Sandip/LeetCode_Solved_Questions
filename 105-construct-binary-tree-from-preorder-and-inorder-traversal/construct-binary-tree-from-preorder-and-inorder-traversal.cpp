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
    int search(vector<int> inOrder, int target) {
        for(int i=0; i<inOrder.size(); i++) {
            if(inOrder[i] == target) return i;
        }
        return -1;
    }
    TreeNode* constructTree(vector<int> preOrder, vector<int> inOrder, int &preOrderIdx, int inOrderStart, int inOrderEnd) {
        // base Case :
        if(preOrderIdx >= preOrder.size() || inOrderStart > inOrderEnd) {
            return NULL;
        }

        // solve 1 case :
        TreeNode* newNode = new TreeNode(preOrder[preOrderIdx]);
        preOrderIdx++;

        int position = search(inOrder, newNode->val);

        newNode->left = constructTree(preOrder, inOrder, preOrderIdx, inOrderStart, position-1);
        newNode->right = constructTree(preOrder, inOrder, preOrderIdx, position+1, inOrderEnd);

        return newNode;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderIdx = 0;
        int inOrderStart = 0;
        int inOrderEnd = inorder.size();
        return constructTree(preorder, inorder, preOrderIdx, inOrderStart, inOrderEnd);
    }
};