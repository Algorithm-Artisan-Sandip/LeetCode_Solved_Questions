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

 // Hare and Tortoise Algorithm (Fast and Slow Pointer) : 
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL) return NULL;  // corner cases
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = nullptr;
        while(fast != NULL && fast->next != NULL) {
            fast = fast->next;
            if(fast != NULL) {
                fast = fast->next;
            }
            prev = slow;
            slow = slow->next;
        }
        prev->next = slow->next;
        return head;
    }
};