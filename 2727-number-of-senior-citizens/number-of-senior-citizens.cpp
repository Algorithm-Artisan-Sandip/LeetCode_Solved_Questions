class Solution {
public:
    int countSeniors(vector<string>& details) {
        int size = details.size();
        int count = 0;
        for(auto& detail : details) {
            if(detail[11]-'0' > 6) count++;
            if(detail[11]-'0' == 6 && detail[12]-'0' > 0) count++;
        }

        return count;
    }
};