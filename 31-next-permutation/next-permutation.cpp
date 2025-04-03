class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        bool flag = false;
        int breakPnt = -1;
        // find the break point : 
        for(int i=nums.size()-1; i>0; i--) {
            if(nums[i] > nums[i-1]) {
                breakPnt = i-1;
                break;
            }
        }
        // if no break point exist then simply reverse the array and return : 
        if(breakPnt == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // if break point exist then swap the break point element with the bigger than this which is smallest among the elements on the right of the break point : 
        for(int i = nums.size()-1; i>breakPnt; i--) {
            if(nums[i] > nums[breakPnt]) {
                swap(nums[i], nums[breakPnt]);
                break;
            }
        }
        // sort all the elements to the right of the breakpoint and return : 
        reverse(nums.begin()+breakPnt+1, nums.end());
    }
};