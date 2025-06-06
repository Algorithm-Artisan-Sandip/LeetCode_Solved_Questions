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
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* temp = head;
        ListNode* prev = nullptr;
        
        while(temp != NULL) {
            ListNode* var = temp->next;
            if(temp->val == val) {
                if(temp == head) head = var;
                else prev->next = var;
            }
            else prev = temp;

            temp = var;
        }
        return head;
    }
};