// Approach 2 : T.C.=O(n), S.C.=O(n) : Using map : 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // creating the entries of each element in the map : 
        unordered_map<int,int> mpp;
        for(int i=0; i<nums.size(); i++) {
            mpp[nums[i]] = i;
        }

        // checking if the target pair exists or not : 
        for(int i=0; i<nums.size(); i++) {
            int more = target - nums[i];
            if(mpp.find(more) != mpp.end() && mpp[more] != i) {
                return {i, mpp[more]};
            }
        }

        return {-1, -1};
    }
};



// Approach 1 : T.C.=O(n^2), S.C.=O(1) : 
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int size = nums.size();
//         for(int i=0; i<size; i++)
//             for(int j=0; j<size; j++)
//                 if(j!=i && nums[i]+nums[j] == target)
//                     return {i, j};

//         return {-1, -1};
//     }
// };