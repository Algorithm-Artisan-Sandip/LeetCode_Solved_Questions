// Optimized Approach : T.C: O(n), S.C: O(1)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int l = 0, r = height.size()-1;
        while(l<r) {
            maxWater = max(maxWater, (r-l)*min(height[l], height[r]));
            height[r] > height[l] ? l++ : r--;
        }
        return maxWater;
    }
};