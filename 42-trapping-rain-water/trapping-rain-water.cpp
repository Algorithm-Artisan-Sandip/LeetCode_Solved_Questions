// Approach 1 : T.C: O(n), S.C: O(3*n)
class Solution {
private:
    void suffMax(vector<int>& suffixMax, vector<int>& height) {
        int size = height.size();
        suffixMax[size-1] = height[size-1];
        for(int i=size-2; i>=0; i--) {
            suffixMax[i] = max(suffixMax[i+1], height[i]);
        }
    }
public:
    int trap(vector<int>& height) {
        int size = height.size();
        int leftMax = height[0];
        vector<int> suffixMax(height.size());
        int ans = 0;
        suffMax(suffixMax, height);
        for(int i=0; i<size; i++) {
            int leftMax = max(height[i], leftMax);
            int rightMax = suffixMax[i];
            if(height[i] < leftMax && height[i] < rightMax) {
                ans += min(leftMax, rightMax) - height[i];
            }
        }
        return ans;
    }
};