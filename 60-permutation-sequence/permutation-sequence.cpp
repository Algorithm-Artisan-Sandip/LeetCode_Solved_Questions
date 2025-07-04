class Solution {
private:
    // T.C: O(k*n), S.C: O(n) --> as we are not finding all the 
    // permutations when ever the requied one is found we return.
    // Number of full permutations generated so far
    int count = 0; 
    // used[d] == true means digit d has been placed in current
    bool used[10] = {false}; 
    string result; // Will hold the k-th permutation once found

    void findAns(int n, int k, string &current) {
        if ((int)current.size() == n) {
            if (++count == k) {
                result = current;
            }
            return;
        }
        for (int d = 1; d <= n; ++d) {
            // Skip digits already used in the current permutation
            if (used[d]) continue;
            // Early exit: if result is non-empty
            if (!result.empty()) return;
            // Choose digit d for the next position
            used[d] = true;
            current.push_back(char('0' + d));
            findAns(n, k, current);
            // Backtrack
            current.pop_back();
            used[d] = false;
        }
    }

public:
    string getPermutation(int n, int k) {
        string cur;
        findAns(n, k, cur);
        return result;
    }
};
