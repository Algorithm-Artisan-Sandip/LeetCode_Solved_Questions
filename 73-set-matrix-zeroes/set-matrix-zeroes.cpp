class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_map<int, int> zeroRow;
        unordered_map<int, int> zeroCol;
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[0].size(); j++) {
                if(matrix[i][j] == 0) {
                    zeroRow[i] = 1;
                    zeroCol[j] = 1;
                }
            }
        }
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[0].size(); j++) {
                if(zeroRow[i] == 1) {
                    matrix[i][j] = 0;
                }
                if(zeroCol[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }

    }
};