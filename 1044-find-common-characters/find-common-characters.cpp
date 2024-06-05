class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> tally(26, INT_MAX);
        
        for(const string& word : words) {
            vector<int> currentTally(26, 0);
            for(char ch : word) {
                currentTally[ch - 'a']++;
            }
            for(int i = 0; i < 26; i++) {
                tally[i] = min(tally[i], currentTally[i]);
            }
        }
        
        vector<string> ans;
        for(int i = 0; i < 26; i++) {
            while(tally[i] > 0) {
                ans.push_back(string(1, 'a' + i));
                tally[i]--;
            }
        }
        return ans;
    }
};
