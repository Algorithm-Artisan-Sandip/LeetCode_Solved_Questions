// Approach 1 : T.C: O(n), S.C: O(3*n)
class Solution {
private:
    void prefMax(vector<int>& prefixMax, vector<int>& height) {
        int size = height.size();
        prefixMax[0] = height[0];
        for(int i=1; i<size; i++) {
            prefixMax[i] = max(prefixMax[i-1], height[i]);
        }
    }
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
        vector<int> prefixMax(height.size());
        vector<int> suffixMax(height.size());
        int ans = 0;
        prefMax(prefixMax, height);
        suffMax(suffixMax, height);
        for(int i=0; i<size; i++) {
            int leftMax = prefixMax[i];
            int rightMax = suffixMax[i];
            if(height[i] < leftMax && height[i] < rightMax) {
                ans += min(leftMax, rightMax) - height[i];
            }
        }
        return ans;
    }
};