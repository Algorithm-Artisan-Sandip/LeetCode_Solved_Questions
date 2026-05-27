class Solution {
public:
    string greatestLetter(string s) {
        vector<int> lowerCase(26, 0);
        vector<int> upperCase(26, 0);
        
        // Record presence of lowercase and uppercase letters
        for(auto ch : s) {
            if(islower(ch)) {
                lowerCase[ch - 'a'] = 1;
            } else {
                upperCase[ch - 'A'] = 1;
            }
        }
        
        // Iterate backwards to find the greatest letter
        for(int i = 25; i >= 0; i--) {
            if(lowerCase[i] == 1 && upperCase[i] == 1) {
                // Return the uppercase letter as a string
                return string(1, i + 'A'); 
            }
        }
        
        return "";
    }
};
