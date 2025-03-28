// Approach 2 : T.C: O(n^2), S.C: O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0 = 1;  // for the element at 0th col and 0th row
        // keeping track of the zeros in the first col and row of the matrix itself : 
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[0].size(); j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    if(j!=0) matrix[0][j] = 0;
                    else col0 = 0;
                }
            }
        }

        // marking the matrix elements except the first row and col : 
        for(int i=1; i<matrix.size(); i++) {
            for(int j=1; j<matrix[0].size(); j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // setting the first row : 
        if(matrix[0][0] == 0) {
            for(int i=0; i<matrix[0].size(); i++) {
                matrix[0][i] = 0;
            }
        }

        // setting the first col : 
        if(col0 == 0) {
            for(int i=0; i<matrix.size(); i++) {
                matrix[i][0] = 0;
            }
        }
    }
};




// Approach 1 : T.C: O(n^2), S.C: O(n^2)
// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         unordered_map<int, int> zeroRow;
//         unordered_map<int, int> zeroCol;
//         for(int i=0; i<matrix.size(); i++) {
//             for(int j=0; j<matrix[0].size(); j++) {
//                 if(matrix[i][j] == 0) {
//                     zeroRow[i] = 1;
//                     zeroCol[j] = 1;
//                 }
//             }
//         }
//         for(int i=0; i<matrix.size(); i++) {
//             for(int j=0; j<matrix[0].size(); j++) {
//                 if(zeroRow[i] == 1) {
//                     matrix[i][j] = 0;
//                 }
//                 if(zeroCol[j] == 1) {
//                     matrix[i][j] = 0;
//                 }
//             }
//         }

//     }
// };