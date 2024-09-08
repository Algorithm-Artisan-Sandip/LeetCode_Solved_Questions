class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int size = nums.size();

        int maxConsOne = 0, count = 0;

        for(auto& it : nums) {
            if(it == 1) count++;
            else count = 0;
            maxConsOne = max(maxConsOne, count);
        }

        return maxConsOne;
    }
};