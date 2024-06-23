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
    int findLenOfLL(ListNode* head) {
        ListNode* temp = head;
        int count = 0;
        while(temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    ListNode* addTwoNum(ListNode* l1, ListNode* l2, int len1, int len2) {
        ListNode* head = NULL;
        ListNode* temp = nullptr;

        ListNode* temp1 = (len1 >= len2) ? l1 : l2;
        ListNode* temp2 = (len1 >= len2) ? l2 : l1;

        int carry = 0;

        while (temp1 != NULL) {
            int val2 = (temp2 != NULL) ? temp2->val : 0;
            int totalSum = temp1->val + val2 + carry;

            ListNode* var = new ListNode(totalSum % 10);
            carry = totalSum / 10;

            if (head == NULL) {
                head = var;
                temp = head;
            } else {
                temp->next = var;
                temp = temp->next;
            }

            if (temp1 != NULL) temp1 = temp1->next;
            if (temp2 != NULL) temp2 = temp2->next;
        }

        // If carry is still left
        if (carry > 0) {
            temp->next = new ListNode(carry);
        }
        return head;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int length1 = findLenOfLL(l1);
        int length2 = findLenOfLL(l2);
        ListNode* head = addTwoNum(l1, l2, length1, length2);
        return head;
    }
};
