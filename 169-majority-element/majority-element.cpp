// 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt = 0, maxCnt = 0, majoirtyEl = nums[0];

        for(int i=1; i<nums.size(); i++) {
            if(nums[i] == nums[i-1]) cnt++;
            else cnt = 0;

            if(maxCnt < cnt) {
                maxCnt = cnt;
                majoirtyEl = nums[i];
            }
        }

        return majoirtyEl;
    }
};