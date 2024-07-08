class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> track;
        for(char c = 'a'; c <= 'z'; c++) {
            track[c] = 0;
        }
        int i = 0;
        while(i != s.size()) {
            track[s[i]]++;
            i++;
        }

        i = 0;
        while(i != s.size()) {
            if(track[s[i]] == 1) return i;
            i++;
        }

        return -1;
    }
};