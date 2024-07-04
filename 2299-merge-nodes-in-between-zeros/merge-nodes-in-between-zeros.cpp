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
    ListNode* mergeNodes(ListNode* head) {
        int count = head->next->val;
        ListNode* temp = head->next->next;
        ListNode* head1 = NULL;
        ListNode* point = NULL;
        while(temp != NULL) {
            if(temp->val != 0) {
                count += temp->val;
            }
            else if(temp->val == 0) {
                ListNode* temp1 = new ListNode(count);
                if(head1 == NULL) {
                    head1 = temp1;
                    point = head1;
                }
                else {
                    point->next = temp1;
                    point = point->next;
                }
                count = 0;
            }
            temp = temp->next;
        }
        return head1;
    }
};