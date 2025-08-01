class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int leftSum = 0;
        // Take first k cards from the front
        for (int i = 0; i < k; ++i) {
            leftSum += cardPoints[i];
        }
        int ans = leftSum;
        // Now try taking some cards from the end instead of the front
        int rightSum = 0;
        for (int i = 0; i < k; ++i) {
            leftSum -= cardPoints[k - 1 - i];   // remove from front
            rightSum += cardPoints[n - 1 - i];   // add from back
            ans = max(ans, leftSum + rightSum);
        }
        return ans;
    }
};
