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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummyHead = new ListNode(-1); // Dummy node
        ListNode* tail = dummyHead;
        // Traverse both lists until one is exhausted
        while(list1 && list2) {
            if(list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        // Attach remaining nodes of the non-empty list
        if(list1) tail->next = list1;
        if(list2) tail->next = list2;

        ListNode* newHead = dummyHead->next;
        delete dummyHead;
        return newHead;
    }
};
