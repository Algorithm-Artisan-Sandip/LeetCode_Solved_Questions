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
    // Utility function to compute the length of the linked list
    int lenOfLL(ListNode* head) {
        int cnt = 0;
        ListNode* temp = head;
        while (temp) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }

public:
    ListNode* rotateRight(ListNode* head, int k) {
        // Base cases: empty list, one node, or zero rotations
        if (!head || !head->next || k == 0)
            return head;

        // Step 1: Compute length of linked list
        int len = lenOfLL(head);

        // Step 2: Reduce k to within the bounds of the list length
        k = k % len;
        if (k == 0)  // No rotation needed
            return head;

        // Step 3: Find the new tail: (len - k)th node
        ListNode* newTail = head;
        int stepsToNewTail = len - k;
        for (int i = 1; i < stepsToNewTail; i++) {
            newTail = newTail->next;
        }

        // Step 4: Set the new head to the next of new tail
        ListNode* newHead = newTail->next;

        // Step 5: Break the link to rotate
        newTail->next = nullptr;

        // Step 6: Traverse to the end of the new list segment
        ListNode* tail = newHead;
        while (tail != nullptr && tail->next != nullptr) {
            tail = tail->next;
        }

        // Step 7: Connect the end of the rotated segment to the old head
        if (tail != nullptr) {
            tail->next = head;
        }

        // Step 8: Return the new head
        return newHead;
    }
};
