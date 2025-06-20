// Approach 1 : T.C: O(n^2), S.C: O(1)
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long  ans = 0;
        for(int i=0; i<nums.size(); i++) {
            int mini = INT_MAX;
            int maxi = INT_MIN;
            for(int j=i; j<nums.size(); j++) {
                mini = min(mini, nums[j]);
                maxi = max(maxi, nums[j]);
                ans += (maxi-mini);
            }
        }
        return ans;
    }
};