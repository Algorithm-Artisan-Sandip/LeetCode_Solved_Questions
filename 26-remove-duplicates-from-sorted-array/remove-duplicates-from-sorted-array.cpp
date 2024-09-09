// Approach 2 : Two Pointer : T.C: O(n), S.C: O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();

        int pos = 0;
        for(int i=0; i<size; i++) {
            if(nums[pos] != nums[i]) {
                nums[++pos] = nums[i];
            }
        }

        nums.resize(pos+1);
        return pos+1;
    }
};





// Approach 1 : Using Unordered Set : T.C: O(n), S.C: O(n)
// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         unordered_set<int> seen;

//         int pos = 0;
//         for(auto& it : nums) {
//             if(seen.find(it) == seen.end()) {
//                 seen.insert(it);
//                 nums[pos++] = it;
//             }
//         }

//         nums.resize(pos);

//         return pos;
//     }
// };

