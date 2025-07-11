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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return NULL;
        ListNode* evenHead = new ListNode(0);
        ListNode* evenMover = evenHead;
        ListNode* oddHead = new ListNode(0);
        ListNode* oddMover = oddHead;
        ListNode* temp = head;
        int cnt = 0;
        while(temp) {
            if(cnt & 1) {
                oddMover->next = new ListNode(temp->val);
                oddMover = oddMover->next;
            }
            else {
                evenMover->next = new ListNode(temp->val);
                evenMover = evenMover->next;
            }
            temp = temp->next;
            cnt++;
        }
        ListNode* ansHead = evenHead->next;
        delete evenHead;
        evenMover->next = oddHead->next;
        delete oddHead;
        return ansHead;
    }
};