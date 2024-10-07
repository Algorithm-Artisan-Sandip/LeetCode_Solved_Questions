class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        unordered_set<int> st;
        for(auto it : nums) 
            st.insert(it); // inserting only the unique elements

        int maxCnt = 1;
        for(auto it : st) {
            if(st.find(it-1) == st.end()) {
                int x = it;
                int cnt = 0;
                while(st.find(x) != st.end()) {
                    x++;
                    cnt++;
                }
                maxCnt = max(maxCnt, cnt);
            }
        }
        return maxCnt;
    }
};