/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Approach 1 : Using Map : 
// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//         unordered_map<ListNode*, bool> mapping;
//         ListNode* temp = head;
//         while(temp != NULL) {
//             // cycle present : 
//             if(mapping.find(temp) != mapping.end()) return true;
//             // cycle not present : 
//             else {
//                 mapping[temp] = true;
//             }
//             temp = temp->next;
//         }
//         return false;
//     }
// };


// Approach 2 : Tortoise and Hare algorithm : BEST 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL) {
            fast = fast->next;
            slow = slow->next;
            if(fast != NULL) fast = fast->next;
            else return false;
            if(slow==fast) return true;
        }
        return false;
    }
};