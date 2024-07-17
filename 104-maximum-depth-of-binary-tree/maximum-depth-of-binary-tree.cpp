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


// Approach 1 : using recursion.
// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//         if(root == NULL) return 0;

//         int leftSubtreeDepth = maxDepth(root->left);
//         int rightSubtreeDepth = maxDepth(root->right);
//         int maxDepth = max(leftSubtreeDepth, rightSubtreeDepth) + 1;

//         return maxDepth;
//     }
// };


// Approach 2 : using level order traversal.
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        
        int count = 1;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()) {
            TreeNode* currNode = q.front();
            q.pop();

            if(currNode == NULL) {
                if(!q.empty()) {
                    q.push(NULL);
                    count++;
                }
            }

            else {
                if(currNode->left != NULL) {
                    q.push(currNode->left);
                }
                if(currNode->right !=  NULL) {
                    q.push(currNode->right);
                }
            }
        }
        return count;
    }
};