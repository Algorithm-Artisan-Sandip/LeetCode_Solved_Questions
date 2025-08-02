class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen = 0, maxFreqEl = 0;
        int right = 0, left = 0;
        vector<int> freq(26, 0);
        int changes = 0;
        while(right < s.size()) {
            freq[s[right]-'A']++;
            maxFreqEl = max(maxFreqEl, freq[s[right]-'A']);
            while((right-left+1) - maxFreqEl > k) {
                freq[s[left]-'A']--;
                for(int i=0; i<26; i++) {
                    maxFreqEl = max(maxFreqEl, freq[i]);
                }
                left++;
            }
            if((right-left+1) - maxFreqEl <= k) {
                maxLen = max(maxLen, right-left+1);
            }
            right++;
        }
        return maxLen;
    }
};