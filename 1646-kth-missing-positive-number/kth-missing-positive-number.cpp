// Brute Force : Linear time complexity.
// class Solution {
// public:
//     int findKthPositive(vector<int>& arr, int k) {
//         int cnt = 0;
//         int j = 0;
//         for(int i=0; i<arr.size(); i++) {
//             j++;
//             while(j != arr[i]) {
//                 cnt++;
//                 if(cnt == k) return j;
//                 j++;
//             }
//         }
//         return j + (k-cnt);
//     }
// };


// Optimised Approach : Logarithmic Time complexity
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0, high = arr.size()-1;
        
        while(low <= high) {
            int mid = low + (high-low)/2;
            int missing = arr[mid] - (mid+1);
            if(missing < k) low = mid+1;
            else high = mid-1;
        }

        return low+k;
    }
};