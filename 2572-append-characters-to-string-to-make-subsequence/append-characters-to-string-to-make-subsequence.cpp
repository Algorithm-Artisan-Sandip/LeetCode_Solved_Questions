class Solution {
public:
    int appendCharacters(string s, string t) {
        int i=0, j=0;
        while(s[i]!='\0') {
            if(t[j]=='\0') return 0;
            if(s[i]==t[j]) {
                j++;
            }
            i++;
        }
        return t.size()-j;
    }
};