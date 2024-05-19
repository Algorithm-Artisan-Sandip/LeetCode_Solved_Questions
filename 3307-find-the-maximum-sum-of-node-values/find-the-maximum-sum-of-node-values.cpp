class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k,
                              vector<vector<int>>& edges) {
        long long totalSum = 0; 
        int count = 0; 
        int positiveMin = INT_MAX; 
        int negativeMax = INT_MIN; 

        for (int value : nums) {
            int modifiedValue = value ^ k; 
            totalSum += value; 
            int change = modifiedValue - value; 

            if (change > 0) {
                positiveMin = min(positiveMin, change); 
                totalSum += change; 
                count += 1; 
            } else {
                negativeMax = max(negativeMax, change); 
            }
        }

        if (count % 2 == 0) {
            return totalSum; 
        }
        return max(totalSum - positiveMin, totalSum + negativeMax);
    }
};