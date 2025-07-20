class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        // 1) Build rank mapping
        int rank[26];
        for (int i = 0; i < 26; i++) {
            rank[order[i] - 'a'] = i;
        }
        // 2) Compare each adjacent pair
        for (int i = 0; i + 1 < (int)words.size(); i++) {
            const string &A = words[i], &B = words[i+1];
            int len = min(A.size(), B.size());
            int k = 0;
            // find first differing character
            while (k < len && A[k] == B[k]) {
                k++;
            }
            if (k < len) {
                // mismatch: check their rank order
                if (rank[A[k] - 'a'] > rank[B[k] - 'a']) {
                    return false;
                }
            } else {
                // all matched but A is longer than B → invalid
                if (A.size() > B.size()) {
                    return false;
                }
            }
        }
        return true;
    }
};
