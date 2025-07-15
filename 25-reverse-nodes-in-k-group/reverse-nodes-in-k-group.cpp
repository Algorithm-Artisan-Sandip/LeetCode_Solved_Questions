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
    ListNode* reverseLL(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr != nullptr) {
            ListNode* nextToCurr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextToCurr;
        }
        return prev;
    }
    ListNode* getKthNode(ListNode* head, int k) {
        while(head != nullptr && k > 1) {
            head = head->next;
            k--;
        }
        return head;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevGrpTail = nullptr;
        while(temp) {
            // Find the k-th node from current position to check if a group exists
            ListNode* kthNode = getKthNode(temp, k);
            if(kthNode == nullptr) {
                // If less than k nodes remain, connect the last group's tail to them and stop
                if(prevGrpTail != nullptr) {
                    prevGrpTail->next = temp;
                }
                break;
            }
            // Save the next group's head for later reconnection
            ListNode* nextGrpHead = kthNode->next;
            // Detach the current group from the rest of the list
            kthNode->next = nullptr;
            // Reverse the current group and get the new head
            ListNode* reversedHead = reverseLL(temp);
            // Connect the previous group's tail to the new head of this reversed group
            if(prevGrpTail) {
                prevGrpTail->next = reversedHead;
            } else {
                // If this is the first group, update the overall head
                head = reversedHead;
            }
            // Connect the tail of the reversed group (which was the original temp)
            // to the head of the next group
            temp->next = nextGrpHead;
            // Move prevGrpTail to the end of the current reversed group
            prevGrpTail = temp;
            // Move temp to the start of the next group
            temp = nextGrpHead;
        }
        return head;
    }
};