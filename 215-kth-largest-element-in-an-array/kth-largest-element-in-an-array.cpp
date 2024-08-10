// Approach 1 : O(nlogn), using sort function :
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         sort(nums.begin(),nums.end());
//         int idx = nums.size()-k;
//         return nums[idx];
//     }
// };

// Approach 2  : O(n), using priority_queue : 
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;

        for(auto &temp : nums) {
            pq.push(temp);
        }

        while(k-1) {
            pq.pop();
            k--;
        }

        return pq.top();
    }
};