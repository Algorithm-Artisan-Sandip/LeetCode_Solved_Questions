class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int iIdx = -1, fIdx = -1;
        int start = 0, end = nums.size()-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(nums[mid]<target) start = mid+1;
            else if(nums[mid] == target){
                fIdx = mid;
                start = mid+1;
            }
            else end = mid-1;
        }
        start = 0; end = nums.size()-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(nums[mid]<target) start = mid+1;
            else if(nums[mid]==target){
                iIdx = mid;
                end = mid-1;
            }
            else end = mid-1;
        }
        ans.push_back(iIdx);
        ans.push_back(fIdx);
        return ans;
    }
};