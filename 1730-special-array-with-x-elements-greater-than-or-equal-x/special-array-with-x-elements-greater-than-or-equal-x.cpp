class Solution {
private:
    int findAns(vector<int> &nums, int mid) {
        int ans = 0;
        for(int temp : nums) {
            if(temp>=mid) ans++;
        }
        return ans;
    }
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int start = 0;
        int end = nums.size();
        while(start<=end) {
            int mid = start + (end-start)/2;
            int ans = findAns(nums,mid);

            if(ans==mid) return mid;
            else if(ans>mid) start = mid+1;
            else end = mid-1;
        }
        return -1;
    }
};