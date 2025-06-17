// Approach 1 : T.C: O(2*n^2) , S.C: O(2*n)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nge;
        vector<int> ans;
        for(int i=0; i<nums2.size(); i++) {
            bool flag = true;
            for(int j=i+1; j<nums2.size(); j++) {
                if(nums2[i] < nums2[j]) {
                    nge.push_back(nums2[j]);
                    flag = false;
                    break;
                }
            }
            if(flag) nge.push_back(-1);
        }
        for(int i=0; i<nums1.size(); i++) {
            for(int j=0; j<nums2.size(); j++) {
                if(nums1[i] == nums2[j]) {
                    ans.push_back(nge[j]);
                }
            }
        }
        return ans;
    }
};