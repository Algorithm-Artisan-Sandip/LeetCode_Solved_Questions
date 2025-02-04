class Solution {
public:
    int maxAscendingSum(vector<int>& arr) {
        int currSum = arr[0], finalSum = arr[0];
        for(int i=0; i<arr.size()-1; i++) {
            if(arr[i] < arr[i+1]) {
                currSum += arr[i+1];
            }
            else currSum = arr[i+1];
            finalSum = max(finalSum, currSum);
        }
        return finalSum;
    }
};