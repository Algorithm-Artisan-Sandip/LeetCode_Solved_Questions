class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;  

        int n = nums.size();

        map<int, int> freq;
        for (auto it : nums) {
            freq[it]++;
        }

        nums.clear();
        for(auto it : freq) {
            while(it.second--) {
                nums.push_back(it.first);
            }
        }

        int maxGap = INT_MIN;
        for (int i = 1; i < nums.size(); i++) {
            maxGap = max(maxGap, nums[i] - nums[i - 1]);
        }

        return maxGap;
    }
};
