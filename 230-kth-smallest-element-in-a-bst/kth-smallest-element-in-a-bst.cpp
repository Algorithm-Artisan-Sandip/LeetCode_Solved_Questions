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

 // Approach 1 : Recursive : 
// class Solution {
// public:
//     int findTarget(TreeNode* root, int& k) {
//         if(root == NULL) return -1; // if not found then return -1.
//         int leftAns = findTarget(root->left, k);  // find in left part
//         if(leftAns != -1) return leftAns;  // if left part answer found then return
//         k--;  // decrement k each time
//         if(k == 0) return root->val;  // if k becomes zero then the node's data is our desired value.
//         return findTarget(root->right, k); // find and return answer in right part.
//     }

//     int kthSmallest(TreeNode* root, int k) {
//         return findTarget(root, k);
//     }
// };


// Approach 2 : Heaps : 
// class Solution {
// public:
//     void storeFirstK(priority_queue<int, vector<int>, greater<int>>& pq, TreeNode* root, int& k) {
//         if (!root || k <= 0) return;

//         // In-order traversal: visit left subtree
//         storeFirstK(pq, root->left, k);

//         // Store the current node's value and decrement k
//         if (k > 0) {
//             pq.push(root->val);
//             k--; // Only decrement after actually storing the value
//         }

//         // In-order traversal: visit right subtree
//         storeFirstK(pq, root->right, k);
//     }

//     int kthSmallest(TreeNode* root, int k) {
//         priority_queue<int, vector<int>, greater<int>> pq;

//         // Store the first k elements in the min-heap
//         storeFirstK(pq, root, k);

//         // The top element is the k-th smallest element
//         return pq.top();
//     }
// };


class Solution {
public:
    int getAns(TreeNode* root, int& k) {
        if (!root) return -1;

        // left subtree
        int left = getAns(root->left, k);
        if (k == 0) return left;

        // processing current node : 
        k--;
        // If k is 0 after processing this node, return the current node's value
        if (k == 0) return root->val;

        // right subtree : 
        return getAns(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        return getAns(root, k);
    }
};
