/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    int findLenOfLL(ListNode* head) {
        int count = 0;
        while(head != NULL) {
            count++;
            head = head->next;
        }
        return count;
    }

    TreeNode* makeBST(ListNode*& head, int n) {
        if(n == 0 || head == NULL) return NULL;

        TreeNode* leftST = makeBST(head, n/2);

        TreeNode* root = new TreeNode(head->val);
        root->left = leftST;
        head = head->next;

        TreeNode* rightST = makeBST(head, n-n/2-1);
        root->right = rightST;
        
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        int len = findLenOfLL(head);
        return makeBST(head, len);
    }
};