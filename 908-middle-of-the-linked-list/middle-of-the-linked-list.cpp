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
    int findLenOfLL(ListNode* head) {
        ListNode* temp = head;
        int count = 0;
        while(temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }
    ListNode* middleNode(ListNode* head) {
        int len = findLenOfLL(head);
        int count = 1;
        ListNode* temp = head;
        while(count != (len/2 + 1)) {
            count++;
            temp = temp->next;
        }
        return temp;
    }
};