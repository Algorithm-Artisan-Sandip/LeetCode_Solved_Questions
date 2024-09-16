// Approach 2 : Optimal --> Without using an extra array : 
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // step 1 : transposing the matrix : 
        for(int i=0; i<n; i++) 
            for(int j=0; j<n && i != j; j++) 
                swap(matrix[i][j], matrix[j][i]);

        // step 2 : reversing each row of the matrix : 
        for(int i=0; i<n; i++)
            reverse(matrix[i].begin(), matrix[i].end());
    }
};


// // Approach 1 : Brute Force --> Using an extra array : 
// class Solution {
// public:
//     void rotate(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         vector<vector<int>> rotated(n, vector<int>(n,0));
	    
// 	    for (int i = 0; i < n; i++)
//             for (int j = 0; j < n; j++) 
//                 rotated[j][n - i - 1] = matrix[i][j];

//         for(int i = 0; i < n; i++)
//             for(int j = 0; j < n; j++)
//                 matrix[i][j] = rotated[i][j];
//     }
// };