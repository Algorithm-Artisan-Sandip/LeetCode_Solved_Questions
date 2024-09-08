class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> ans;
        int i = 0, j=0;
        while(i<nums1.size() && j<nums2.size()) {
            if(nums1[i] == nums2[j]) {
                if(ans.empty() || nums1[i] != ans.back())  // here I made a mistake of not considering when arr is empty then accessing its back will result in runtime error, I have corrected it by reordering the conditions.
                    ans.push_back(nums1[i]);
                i++; j++;
            }
            else if(nums1[i] > nums2[j]) j++;
            else i++;
        }

        return ans;
    }
};