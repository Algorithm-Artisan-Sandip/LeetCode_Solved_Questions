class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int size = nums.size();
        if(size == 1) return 1;
        if(size == 2) return 2;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int miniIdx = -1, maxiIdx = -1;
        for(int i=0; i<size; i++) {
            if(maxi < nums[i]) {
                maxi = nums[i];
                maxiIdx = i;
            }
            if(mini > nums[i]) {
                mini = nums[i];
                miniIdx = i;
            }
        }
        int leftDeletion, rightDeletion, bothSideDeletion;
        if(miniIdx > maxiIdx) {
            leftDeletion = miniIdx+1;
            rightDeletion = size-maxiIdx;
            bothSideDeletion = maxiIdx+1 + (size-miniIdx);
        }
        else {
            leftDeletion = maxiIdx+1;
            rightDeletion = size-miniIdx;
            bothSideDeletion = miniIdx+1 + (size-maxiIdx);
        }
        
        int ans = min(leftDeletion, min(rightDeletion, bothSideDeletion));
        return ans;
    }
};