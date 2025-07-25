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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Dummy node : starting point of the result list
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        int carry = 0;          
        while (l1 || l2 || carry) {
            int sum = carry;
            // Add digit from l1 if available
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            // Add digit from l2 if available
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }
        // Result list starts from dummy->next
        ListNode* head = dummy->next;
        delete dummy;
        return head;
    }
};