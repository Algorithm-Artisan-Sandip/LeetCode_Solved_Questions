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
private:
    int findLenofLL(ListNode* head) {
        ListNode* temp = head;
        int count = 0;
        while(temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int size = findLenofLL(head);

        //finding first val : 
        int track = k;
        ListNode* temp1 = head;
        while(--track) {
            temp1 = temp1->next;
        }
        int val1 = temp1->val;

        //finding second val : 
        track = size - k;
        ListNode* temp2 = head;
        while(track--) {
            temp2 = temp2->next;
        }
        int val2 = temp2->val;

        temp1->val = val2;
        temp2->val = val1;

        return head;
    }
};