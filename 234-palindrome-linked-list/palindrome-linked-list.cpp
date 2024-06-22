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
    void reverseLL(ListNode* &head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr != NULL) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        head = prev;
    }
    ListNode* midOfLL(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        int count = 0;
        while(fast != NULL) {
            fast = fast->next;
            count++;
            if(fast != NULL) {
                fast = fast->next;
                count++;
                slow = slow->next;
            }
        }
        return slow;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* mid = midOfLL(head);
        reverseLL(mid->next);
        ListNode* temp1 = head;
        ListNode* temp2 = mid->next;
        bool flag = true;
        while(temp2 != NULL) {
            if(temp1->val != temp2->val) {
                flag = false;
                break;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return flag;
    }
};