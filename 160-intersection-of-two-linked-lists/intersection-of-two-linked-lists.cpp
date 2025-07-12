/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        unordered_map<ListNode*, int> mp;
        ListNode* mover1 = head1;
        while(mover1 != nullptr) {
            mp[mover1] = 1;
            mover1 = mover1->next;
        }
        ListNode* mover2 = head2;
        while(mover2 != nullptr) {
            if(mp.find(mover2) != mp.end()) {
                return mover2;
            }
            mp[mover2] = 1;
            mover2 = mover2->next;
        }
        return nullptr;
    }
};