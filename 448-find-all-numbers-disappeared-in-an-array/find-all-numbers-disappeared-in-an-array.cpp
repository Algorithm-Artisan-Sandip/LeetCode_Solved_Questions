class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int size = nums.size();
        vector<int> temp(size+1, 0);

        for(auto& it : nums)
            temp[it]++;

        vector<int> ans;
        for(int i=1; i<size+1; i++) 
            if(temp[i] == 0) ans.push_back(i);

        return ans;
    }
};