class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> sMap;
        unordered_map<char, char> tMap;

        for (int i = 0; i < s.size(); i++) {
            if (sMap.count(s[i])) {
                if (sMap[s[i]] != t[i]) {
                    return false;
                }
            } else {
                sMap[s[i]] = t[i];
            }

            if (tMap.count(t[i])) {
                if (tMap[t[i]] != s[i]) {
                    return false;
                }
            } else {
                tMap[t[i]] = s[i];
            }
        }

        return true;
    }
};
