class Solution {
private:
    void findAns(int idx, set<string>& ans, string& s) {
        if(idx == s.size()) {
            ans.insert(s);
            return;
        }
        if(isalpha(s[idx])) s[idx] = toupper(s[idx]);
        findAns(idx+1, ans, s);
        if(isalpha(s[idx])) s[idx] = tolower(s[idx]);
        findAns(idx+1, ans, s);
    }
public:
    vector<string> letterCasePermutation(string s) {
        set<string> ans;
        findAns(0, ans, s);
        vector<string> finalAns(ans.begin(), ans.end());
        return finalAns;
    }
};