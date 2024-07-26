class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> vec(26,0);
        for(auto& ch : sentence) {
            vec[ch-'a']++;
        }

        int count = 0;
        for(auto& val : vec) {
            if(val == 0) return false;
        }
        return true;
    }
};