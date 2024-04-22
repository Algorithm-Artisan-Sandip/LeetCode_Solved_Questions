class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> result(size, 1);

        
        int leftProduct = 1;
        for (int i = 0; i < size; i++) {
            result[i] = leftProduct;
            leftProduct *= nums[i];
        }

        
        int rightProduct = 1;
        
        for(int i=size-1; i>=0; i--){
            result[i] *= rightProduct;
            rightProduct *= nums[i];
        }

        return result;
    }
};
