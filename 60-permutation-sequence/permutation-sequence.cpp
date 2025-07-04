class Solution {
public:
    // T.C: O(n^2) --> for iteration and
    // erase operation, S.C: O(1)
    string getPermutation(int n, int k) {
        vector<int> nums;
        int fact = 1;
        string ans = "";

        // Build initial factorial = (n-1)! 
        // and fill nums = [1, 2, …, n-1]
        for (int i = 1; i < n; i++) {
            fact *= i; 
            nums.push_back(i);
        }
        nums.push_back(n); // finally add n itself
        k = k - 1;  // zero-based index

        while (!nums.empty()) {
            // how many perms per first-digit choice
            int blockSize = fact;
            // element at this index has to be chosen
            int index = k / blockSize;  
            ans += to_string(nums[index]);  
            // remove it from the pool
            nums.erase(nums.begin() + index);

            if (nums.empty()) 
                break;
            // position within the block
            k = k % blockSize;
            // step down: (remaining-1)!               
            fact = fact / (int)nums.size();  
        }
        return ans;
    }
};
