class Solution {
private:
    int findMaxBitOr(const vector<int>& arr) {
        int max_or = 0;
        for (int x : arr) {
            max_or |= x;
        }
     return max_or;
    }
    void findAns(int idx, int& maxBitOr, int currBitOr, int& count, int n, vector<int> ans, vector<int>& arr) {
        if(idx == n) {
            if(maxBitOr == currBitOr) count++;
            return;
        }
        ans.push_back(arr[idx]);
        findAns(idx+1, maxBitOr, (currBitOr | arr[idx]), count, n, ans, arr);
        ans.pop_back();
        findAns(idx+1, maxBitOr, currBitOr, count, n, ans, arr);
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxBitOr = findMaxBitOr(nums);
        vector<int> ans;
        int count = 0;
        findAns(0, maxBitOr, 0, count, nums.size(), ans, nums);
        return count;
    }
};