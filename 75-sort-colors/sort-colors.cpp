class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size()-1, idx = 0;
        while(idx<=right){
            if(nums[idx]==0){
                swap(nums[left],nums[idx]);
                left++; idx++;
            }
            else if(nums[idx]==2){
                swap(nums[right],nums[idx]);
                right--;
            }
            else idx++;
        }
    }
    
};