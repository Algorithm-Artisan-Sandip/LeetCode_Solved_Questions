// Approach 1 : O(nlogn), using sort function :
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         sort(nums.begin(),nums.end());
//         int idx = nums.size()-k;
//         return nums[idx];
//     }
// };

// Approach 2  : O(nlogn), using priority_queue : 
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         priority_queue<int> pq;

//         for(auto &temp : nums) {
//             pq.push(temp);
//         }

//         while(k-1) {
//             pq.pop();
//             k--;
//         }

//         return pq.top();
//     }
// };

// Approach 3 : efficient space complexity : 
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        // pushing first k elements in min_heap :
        for(int i=0; i<k; i++) {
            pq.push(nums[i]);
        }

        // now processing other elements : 
        for(int i=k; i<nums.size(); i++) {
            if(nums[i] > pq.top()) {
                pq.pop();
                pq.push(nums[i]);
            }
        }

        return pq.top();
    }
};