class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i=0, sum=0, Max = nums[0];
        int size = nums.size();
        while(i<size){
            sum+=nums[i];
            Max = max(Max,sum);
            if(sum<0) sum=0;
            i++;
        }
        return Max;
    }
};