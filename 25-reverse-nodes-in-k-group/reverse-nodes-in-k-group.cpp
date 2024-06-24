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
    int lenOfLL(ListNode* head) {
        ListNode* temp = head;
        int count = 0;
        while(temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }
    ListNode* reverseInKGroups(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nextNode = NULL;
        int count = 0;

        if(k > lenOfLL(head)) {
            return head;
        }

        while(count<k && curr != NULL) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            count++;
        }

        if(nextNode != NULL) {
            head->next = reverseInKGroups(nextNode, k);
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        return reverseInKGroups(head, k);
    }
};