class Solution {
public:
    bool detectCapitalUse(string word) {
        int upperCnt = 0;
        for(char ch : word) {
            if(isupper(ch)) {
                upperCnt++;
            }
        }
        if(upperCnt == word.size() || upperCnt == 0 || (upperCnt == 1 && isupper(word[0]))) {
            return true;
        }
        return false;
    }
};