class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int cdigitsy = 0;
        for(int i=digits.size()-1; i>=0; i--) {
            if(digits[i] == 9) {
                digits[i] = 0;
                cdigitsy = 1;
                continue;
            }
            else {
                digits[i] += 1;
                break;
            }
        }
        if(digits[0] == 0) {
            vector<int> ans(digits.size()+1);
            ans[0] = 1;
            for(int i=1; i<=digits.size(); i++) {
                ans[i] = digits[i-1];
            }
            return ans;
        }
        return digits;
    }
};