class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> productCount; 
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int product = nums[i] * nums[j];
                productCount[product]++;
            }
        }

        for (auto& [product, freq] : productCount) {
            if (freq > 1) {
                count += (freq * (freq - 1)) / 2;  // freq = 3 we can rearrange them into 3*(3-1)/2 = 3 different tuples.
            }
        }

        return count * 8;  // as tuple of 4 elements can be rearraged in 8 different ways.
    }
};
