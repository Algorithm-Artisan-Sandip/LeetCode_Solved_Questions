class Solution {
public:
    int numberOfSpecialChars(string word) {
        // 0 default value
        // 69 if caps appear before
        // 1 if caps appear later
        // -1 if condition failed
        vector<int> tracker(26, 0);
        int specialCnt = 0;
        for(size_t i = 0; i<word.size(); i++) {
            if(word[i] >= 97 && word[i] <= 122) {
                if(tracker[word[i]-'a'] == 0) {
                    tracker[word[i]-'a'] = 1;
                }
                else if(tracker[word[i]-'a'] == 69) {
                    tracker[word[i]-'a'] = -1;
                }
            }
            else if(word[i] >= 65 && word[i] <= 90) {
                if(tracker[word[i]-'A'] == 0) {
                    tracker[word[i]-'A'] = -1;
                }
                if(tracker[word[i]-'A'] == 1) {
                    tracker[word[i]-'A'] = 69;
                }
            }
        }
        for(auto nums : tracker) {
            if(nums == 69) specialCnt++;
        }
        return specialCnt;

    }
};