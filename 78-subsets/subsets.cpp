class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> cur;

        function<void(int)> explore = [&](int index) {
            if (index == nums.size()) {
                result.push_back(cur);
                return;
            }
            cur.push_back(nums[index]);
            explore(index + 1);
            cur.pop_back();
            explore(index + 1);
        };

        explore(0);
        return result;
    }
};