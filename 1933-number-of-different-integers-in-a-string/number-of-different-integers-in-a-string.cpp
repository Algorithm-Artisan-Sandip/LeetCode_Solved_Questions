class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> uniqueNumbers;
        int i = 0;
        int n = word.size();

        while (i < n) {
            if (isdigit(word[i])) {
                string numStr;
                // Collect the full number as a string
                while (i < n && isdigit(word[i])) {
                    numStr += word[i];
                    i++;
                }
                // Remove leading zeros
                numStr.erase(0, numStr.find_first_not_of('0'));
                if (numStr.empty()) {
                    numStr = "0"; // Handle the case where the number is only zeros
                }
                uniqueNumbers.insert(numStr);
            } else {
                i++;
            }
        }

        return uniqueNumbers.size();
    }
};