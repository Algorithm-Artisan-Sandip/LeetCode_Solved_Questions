class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        unordered_map<int, int> freq;
        long long total = n*(n-1)/2;
        long long good = 0;
        for(int i=0; i<nums.size(); i++) {
            int diff = nums[i]-i;
            good += freq[diff];
            freq[diff]++;
        }
        return total - good;
    }
};