class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int> seen;

        int pos = 0;
        for(auto& it : nums) {
            if(seen.find(it) == seen.end()) {
                seen.insert(it);
                nums[pos++] = it;
            }
        }

        nums.resize(pos);

        return pos;
    }
};