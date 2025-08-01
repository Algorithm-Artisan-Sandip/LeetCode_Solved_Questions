class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int right = 0, left = 0;
        int maxLen = 0;
        unordered_map<int, int> mp;
        while(right < fruits.size()) {
            mp[fruits[right]]++;
            if(mp.size() > 2) {
                while(mp.size() > 2) {
                    mp[fruits[left]]--;
                    if(mp[fruits[left]] == 0) {
                        mp.erase(fruits[left]);
                    }
                    left++;
                }
            }
            if(mp.size() <= 2) {
                maxLen = max(maxLen, right-left+1);
            }
            right++;
        }
        return maxLen;
    }
};