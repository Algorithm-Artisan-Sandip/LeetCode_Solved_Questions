class Solution {
public:
    int numberOfSubstrings(string s) {
        // Stores the last seen index of 'a', 'b', and 'c'
        // arr[0] → 'a', arr[1] → 'b', arr[2] → 'c'
        int arr[3] = {-1, -1, -1};
        int subStrCnt = 0;  // Total count of valid substrings
        for(int i = 0; i < s.size(); i++) {
            // Update the last seen index of the current character
            arr[s[i] - 'a'] = i;
            // If all three characters have been seen at least once
            if(arr[0] != -1 && arr[1] != -1 && arr[2] != -1) {
                // The number of valid substrings ending at index i is:
                // (minimum last index among 'a', 'b', 'c') + 1
                subStrCnt += 1 + min(arr[0], min(arr[1], arr[2]));
            }
        }
        return subStrCnt;
    }
};
