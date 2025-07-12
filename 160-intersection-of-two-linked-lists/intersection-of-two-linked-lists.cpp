/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  private:
    int findLenLL(ListNode* head) {
        ListNode* temp = head;
        int cnt = 0;
        while(temp) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
    ListNode* findIntersection(ListNode* lrgHead, ListNode* smlHead, int cover) {
        ListNode* smlTemp = smlHead;
        ListNode* lrgTemp = lrgHead;
        // Advance the longer list by 'cover' nodes
        while(cover--)
            lrgTemp = lrgTemp->next;
        // Move both pointers one step at a time until they meet
        while(true) {
            if(smlTemp == lrgTemp) return smlTemp;
            if(smlTemp == NULL || lrgTemp == NULL) break;
            smlTemp = smlTemp->next;
            lrgTemp = lrgTemp->next;
        }
        return NULL;
    }
public:
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        int len1 = findLenLL(head1);
        int len2 = findLenLL(head2);
        if(len1 > len2) {
            return findIntersection(head1, head2, len1 - len2);
        }
        else {
            return findIntersection(head2, head1, len2 - len1);
        }
        return NULL;
    }
};