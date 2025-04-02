// Approach 1 : Brute Force : T.C : O(nlogn), S.C : O(n) : 
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int size = nums.size();
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        int mid = (size-1)/2;
        int end = size-1;
        for(int i=0; i<size; i++) {
            nums[i] = (i%2 == 0) ? sorted[mid--] : sorted[end--];
        }
    }
};