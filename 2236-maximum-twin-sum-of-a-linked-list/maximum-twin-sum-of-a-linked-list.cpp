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


// Approach 2 : Simply using array : 
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> arr;
        while(head) {
            arr.push_back(head->val);
            head = head->next;
        }
        int largest = INT_MIN;
        int size = arr.size();
        for(int i=0; i<size/2; i++) {
            int temp = arr[i] + arr[size-i-1];
            largest = (largest < temp) ? temp : largest;
        }
        return largest;
    }
};



 // Approach 1 : Using Hare and Tortoise algorithm
// class Solution {
// private:
//     ListNode* findMid(ListNode* head, stack<int>& halfOfLL) {
//         ListNode* fast = head;
//         ListNode* slow = head;
        
//         while(fast && fast->next) {
//             halfOfLL.push(slow->val);
//             slow = slow->next;
//             fast = fast->next->next;
//         }
//         return slow;
//     }

// public:
//     int pairSum(ListNode* head) {
//         stack<int> halfOfLL;
//         ListNode* mid = findMid(head, halfOfLL); 

//         int largest = INT_MIN;
//         while(mid) {
//             int temp = mid->val + halfOfLL.top();
//             largest = max(largest, temp);
//             halfOfLL.pop();
//             mid = mid->next;
//         }
//         return largest;
//     }
// };

