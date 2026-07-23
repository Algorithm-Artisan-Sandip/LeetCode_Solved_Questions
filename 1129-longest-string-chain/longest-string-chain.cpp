class Solution {
private:
    // Helper function to check if str1 is a valid predecessor of str2
    bool isPredecessor(const string& str1, const string& str2) {
        // Condition 1: str2 must be exactly 1 character longer than str1
        if (str2.length() != str1.length() + 1) return false;

        int i = 0; // Pointer for str1
        int j = 0; // Pointer for str2

        // Two-pointer scan to check if str1 is a subsequence of str2
        while (i < str1.length() && j < str2.length()) {
            if (str1[i] == str2[j]) {
                i++; // Only move str1 pointer if characters match
            }
            j++; // Always move str2 pointer
        }

        // If we successfully matched every single character of str1, it's valid
        return i == str1.length();
    }

public:
    int longestStrChain(vector<string>& words) {
        if (words.empty()) return 0;

        // 1. CRUCIAL STEP: Sort the words by their lengths.
        // This ensures smaller words are always processed before larger words.
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.length() < b.length();
        });

        int n = words.size();
        vector<int> dp(n, 1); // dp[i] stores the max chain length ending at words[i]
        int maxLength = 1;

        // 2. The standard LIS nested loop structure
        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                // Modified IF Statement: Check if words[prev] can precede words[i]
                if (isPredecessor(words[prev], words[i]) && dp[prev] + 1 > dp[i]) {
                    dp[i] = dp[prev] + 1;
                }
            }
            maxLength = max(maxLength, dp[i]);
        }

        return maxLength;
    }
};
