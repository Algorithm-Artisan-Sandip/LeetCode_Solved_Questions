class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lowerCase(26, 0);
        vector<int> upperCase(26, 0);
        int specialCnt = 0;
        for(auto ch : word) {
            if(islower(ch)) {
                lowerCase[ch-'a'] = 1;
            }
            else {
                upperCase[ch-'A'] = 1;
            }
        }
        for(int i=0; i<26; i++) {
            if(lowerCase[i] == 1 && upperCase[i] == 1) {
                specialCnt++;
            }
        }
        return specialCnt;
    }
};