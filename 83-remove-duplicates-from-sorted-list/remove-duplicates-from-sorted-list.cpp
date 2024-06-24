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
    ListNode* uniqueElements(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* temp = head;
        while(temp->next != NULL) {
            ListNode* var = temp->next;
            if(temp->val == var->val) {
                temp->next = var->next;
                delete var;
            }
            else {
                temp = temp->next;
            }
        }
        return head;
    }
    ListNode* deleteDuplicates(ListNode* head) {
        return uniqueElements(head);
    }
};