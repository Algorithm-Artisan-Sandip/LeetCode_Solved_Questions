class Solution {
private:
    void findAns(int idx, int& count, int target, int n, vector<int>& arr) {
        if(idx == n) {
            if(target == 0) count++;
            return;
        }
        findAns(idx+1, count, target+arr[idx], n, arr);
        findAns(idx+1, count, target-arr[idx], n, arr);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans = 0;
        findAns(0, ans, target, nums.size(), nums);
        return ans;
    }
};