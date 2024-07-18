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
    TreeNode* constructTree(vector<int> inOrder, vector<int> postOrder, int inOrderStart, int inOrderEnd, int &postOrderIdx) {
        if(postOrderIdx < 0 || inOrderStart > inOrderEnd) {
            return NULL;
        }

        TreeNode* newNode = new TreeNode(postOrder[postOrderIdx]);
        postOrderIdx--;

        int position = search(inOrder, newNode->val);

        newNode->right = constructTree(inOrder, postOrder, position+1, inOrderEnd, postOrderIdx);
        newNode->left = constructTree(inOrder, postOrder, inOrderStart, position-1, postOrderIdx);

        return newNode;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postOrderIdx = postorder.size() - 1;
        int inOrderStart = 0;
        int inOrderEnd = postorder.size() - 1;
        return constructTree(inorder, postorder, inOrderStart, inOrderEnd, postOrderIdx);
    }
};