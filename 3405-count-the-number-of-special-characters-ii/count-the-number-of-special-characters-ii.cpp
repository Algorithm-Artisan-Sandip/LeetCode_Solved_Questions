class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lastLower(26, -1);
        vector<int> firstUpper(26, -1);
        int specialCnt = 0;
        // populate lastLower and firstUpper : 
        for(size_t i=0; i<word.size(); i++) {
            if(islower(word[i])) {
                lastLower[word[i]-'a'] = i;
            }
            else {
                if(firstUpper[word[i] - 'A'] == -1) {
                    firstUpper[word[i]-'A'] = i;
                }
            }
        }
        // now find the special letters : 
        for(int i=0; i<26; i++) {
            if(lastLower[i] != -1 && firstUpper[i] != -1 && lastLower[i] < firstUpper[i]) {
                specialCnt++;
            }
        }
        return specialCnt;
    }
};