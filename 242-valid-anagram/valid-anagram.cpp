class Solution {
public:
    bool isAnagram(string s, string t) {
        int ssize = s.size();
        int tsize = t.size();
        if(ssize != tsize) return false;
        else {
            unordered_map<char, int> mapping;
            for(int i=0; i<ssize; i++) {
                mapping[s[i]]++;
            }
            for(int i=0; i<tsize; i++) {
                bool flag = mapping.count(t[i]);
                if(flag) mapping[t[i]]--;
            }
            for(auto& t : mapping) {
                if(t.second != 0) return false;
            }
        }
        return true;
    }
};