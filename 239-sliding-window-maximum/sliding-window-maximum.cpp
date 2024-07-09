class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        for(int i=0; i<k; i++) {
            while(!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        for(int i=k; i<nums.size(); i++) {
            ans.push_back(nums[dq.front()]);

            // removal :
            // out of bound cases :
            if(!dq.empty() && i-dq.front() >= k) {
                dq.pop_front();
            }
            // if back element is smaller than current element :
            while(!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        // last window :
        ans.push_back(nums[dq.front()]);

        return ans;
    }
};