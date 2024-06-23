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
    void insertInAns(ListNode* &head, ListNode* &tail, int value) {
        ListNode* newNode = new ListNode(value);
        if (head == NULL) {
            head = newNode;
            tail = head;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    ListNode* mergeLists(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        ListNode* tail = NULL;

        while (l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val) {
                insertInAns(head, tail, l1->val);
                l1 = l1->next;
            } else {
                insertInAns(head, tail, l2->val);
                l2 = l2->next;
            }
        }

        while (l1 != NULL) {
            insertInAns(head, tail, l1->val);
            l1 = l1->next;
        }

        while (l2 != NULL) {
            insertInAns(head, tail, l2->val);
            l2 = l2->next;
        }

        return head;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        return mergeLists(list1, list2);
    }
};
