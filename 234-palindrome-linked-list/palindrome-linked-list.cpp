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
    ListNode* reverseLL(ListNode* newHead) {
        ListNode* prev = nullptr;
        ListNode* curr = newHead;
        while(curr != nullptr) {
            ListNode* nextToCurr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextToCurr; 
        }
        newHead = prev;
        return newHead;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        // finding the middle of the linked list using slow and fast pointers
        while(fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        // reversing the second half of the list
        ListNode* newHead = reverseLL(slow->next);
        // comparing the first half and the reversed second half
        ListNode* first = head;
        ListNode* second = newHead;
        while(second != nullptr) {
            if(first->val != second->val) {
                reverseLL(newHead);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        reverseLL(newHead);
        return true;
    }
};