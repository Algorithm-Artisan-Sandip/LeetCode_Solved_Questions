class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k > s.size()) return false;
        vector<int> freq(26, 0);
        for(char ch : s){
            freq[ch - 'a']++;
        }
        for(int it : freq){
            if(it % 2) k--;
        }
        return k>=0;
    }
};