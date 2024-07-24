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
    void createElArr(TreeNode* root, vector<int>& arr) {
        if(root == NULL) {
            return;
        }

        arr.push_back(root->val);
        createElArr(root->left, arr);
        createElArr(root->right, arr);
    }
    int findSecondMinimumValue(TreeNode* root) {
        vector<int> arr;

        createElArr(root, arr);
        sort(arr.begin(),arr.end());
        for(int i=0; i<arr.size()-1; i++) {
            if(arr[i] != arr[i+1]) return arr[i+1];
        }

        return -1;
    }
};