class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i=0, ans = 0;
        for(int j=0; j<nums2.size(); j++) {
            if(i<nums1.size() && nums1[i] > nums2[j]) {  // iterating till the last largervalue than nums2[i]
                i++;
            }
            if(i<nums1.size() && i <= j) {  // if thementioned conditions meet
                ans = max(ans, j-i);
            }
        }
        return ans;
    }
};