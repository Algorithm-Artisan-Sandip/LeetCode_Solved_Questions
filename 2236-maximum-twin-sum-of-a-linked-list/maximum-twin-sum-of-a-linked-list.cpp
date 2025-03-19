class Solution {
private:
    ListNode* findMid(ListNode* head, stack<int>& halfOfLL) {
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast && fast->next) {
            halfOfLL.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

public:
    int pairSum(ListNode* head) {
        stack<int> halfOfLL;
        ListNode* mid = findMid(head, halfOfLL); 

        int largest = INT_MIN;
        while(mid) {
            int temp = mid->val + halfOfLL.top();
            largest = max(largest, temp);
            halfOfLL.pop();
            mid = mid->next;
        }
        return largest;
    }
};
