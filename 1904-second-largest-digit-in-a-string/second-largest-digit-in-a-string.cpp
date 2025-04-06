class Solution {
public:
    int secondHighest(string s) {
        int firstNumIdx = -1;
        for(int i=0; i<s.size(); i++) {
            if(isdigit(s[i])) {
                firstNumIdx = i;
                break;
            }
        }
        if(firstNumIdx == -1) return -1;

        int largest = s[firstNumIdx] - '0', secLargest = -1;
        for(int i=firstNumIdx+1; i<s.size(); i++) {
            if(isdigit(s[i])) {
                int digit = s[i]-'0';
                if(digit > largest && digit > secLargest) {
                    secLargest = largest;
                    largest = digit;
                }
                else if(digit < largest && digit > secLargest) {
                    secLargest = digit;
                }
            }
        }
        return secLargest;
    }
};