#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = 0, count = 0, ans = 0;
        int size = s.size();
        
        while (i < size) {
            if (s[i] != ' ' && s[i] != '\0') {
                count++;
                ans = count;
            } 
            else count = 0;
            i++;
        }
        
        return ans;
    }
};
