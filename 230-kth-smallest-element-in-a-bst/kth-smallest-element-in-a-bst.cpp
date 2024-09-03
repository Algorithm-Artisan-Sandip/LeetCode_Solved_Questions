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

// Approach 1 : T.C : O(n), S.C : O(n)
class Solution {
public:
    void storeFirstK(TreeNode* root, vector<int>& arr, int& k) {
        if(root == NULL) return;

        storeFirstK(root->left, arr, k);
        k--;
        arr.push_back(root->val);
        if(k<=0) return;

        storeFirstK(root->right, arr, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> arr;

        int temp = k;
        storeFirstK(root, arr, temp);

        sort(arr.begin(), arr.end());
        return arr[k-1];
    }
};


// Best Approach : O(k) : 
// class Solution {
// public:
//     int getAns(TreeNode* root, int& k) {
//         if (!root) return -1;

//         // left subtree
//         int left = getAns(root->left, k);
//         if (k == 0) return left;

//         // processing current node : 
//         k--;
//         // If k is 0 after processing this node, return the current node's value
//         if (k == 0) return root->val;

//         // right subtree : 
//         return getAns(root->right, k);
//     }

//     int kthSmallest(TreeNode* root, int k) {
//         return getAns(root, k);
//     }
// };
