class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); 
        long long sum = 0;
        int j = 1, cnt = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) 
                continue;

            while (j < nums[i] && cnt < k) { 
                sum += j;
                j++;
                cnt++;
            }

            if (cnt == k) return sum;
            j++;
        }

        // Append remaining numbers if needed
        while (cnt < k) {
            sum += j;
            j++;
            cnt++;
        }

        return sum;
    }
};
