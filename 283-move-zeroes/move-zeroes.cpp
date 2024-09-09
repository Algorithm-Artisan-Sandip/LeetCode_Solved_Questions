class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = -1;
        int size = nums.size();
        // finding the first zero : 
        for(int i=0; i<size; i++) {
            if(nums[i] == 0) {
                j = i;
                break;
            }
        }

        if(j == -1) return;

        // now swapping the zeros with non-zeros : 
        for(int i=j+1; i<size; i++) {
            if(nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};