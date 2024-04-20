class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k %=size;
        // reversing the entire array : 
        reverse(nums.begin(),nums.end());

        // reversing the second part : 
        reverse(nums.begin()+k,nums.end());

        // reversing the first part : 
        reverse(nums.begin(),nums.begin()+k);
    }
};
