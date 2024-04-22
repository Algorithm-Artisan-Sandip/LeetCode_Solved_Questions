class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int sum = 0;
        int maxSum = 0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0) {
                sum = 0;
                continue;
            }
            else {
                sum+=nums[i];
                maxSum = max(maxSum,sum);
            }
        }
        return maxSum;
    }
};