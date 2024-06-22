class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> count(size + 1, 0);
        count[0] = 1;
        int ans = 0, temp = 0;
        for (int var : nums) {
            temp += var & 1;
            if (temp - k >= 0) {
                ans += count[temp - k];
            }
            count[temp]++;
        }
        return ans;
    }
};