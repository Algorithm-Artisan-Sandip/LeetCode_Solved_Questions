class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int n = row*col;

        int start = 0, end = n-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            int rowIndex = mid/col;
            int colIndex = mid%col;
            int currNumber = matrix[rowIndex][colIndex];

            if(currNumber == target) return true;
            if(currNumber > target) end = mid-1;
            else start = mid+1;
        }
        return false;
    }
};