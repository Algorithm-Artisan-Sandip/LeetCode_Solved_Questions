// Approach 2 : Optimized : T.C: O(n+m), S.C: O(3*n)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        vector<int> ans;
        stack<int> st;
        st.push(-1);
        
        // populating the map : 
        for(int i=nums2.size()-1; i>=0; i--) {
            while(st.top()<=nums2[i] && st.top()!=-1) {
                st.pop();
            }
            mp[nums2[i]] = st.top();
            st.push(nums2[i]);
        }

        // finding the answer vector : 
        for(int i=0; i<nums1.size(); i++) {
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};