class Solution {
private:
    void findAns(int idx, string str, vector<string>& ans, 
        vector<vector<string>>& finalAns) {
        if(idx == str.size()) {
            finalAns.push_back(ans);
            return;
        }
        for(int i = idx; i < str.size(); i++) {
            if(isPalindrome(str, idx, i)) {
                ans.push_back(str.substr(idx, i - idx + 1));
                // for the remaining substring starting from i+1
                findAns(i + 1, str, ans, finalAns);
                ans.pop_back(); // Backtrack
            }
        }
    }

    bool isPalindrome(string str, int start, int end) {
        while(start < end) {
            if(str[start] != str[end]) return false;
            start++; end--;
        }
        return true;
    }

public:
    vector<vector<string>> partition(string s) {
        vector<string> ans;
        vector<vector<string>> finalAns;
        findAns(0, s, ans, finalAns);
        return finalAns;
    }
};
