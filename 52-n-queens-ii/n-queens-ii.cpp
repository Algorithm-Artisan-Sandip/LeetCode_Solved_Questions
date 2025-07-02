class Solution {
private:
    bool isSafe(int row, int col, vector<string>& ans, int n) {
        int dupRow = row;
        int dupCol = col;
        // upper-left diagonal : 
        while(row >= 0 && col >= 0) {
            if(ans[row][col] == 'Q') return false;
            row--; col--;
        }
        // left rows :
        row = dupRow; col = dupCol; 
        while(col >= 0) {
            if(ans[row][col] == 'Q') return false;
            col--;
        }
        // bottom-left diagonal : 
        row = dupRow; col = dupCol; 
        while(row < n && col >= 0) {
            if(ans[row][col] == 'Q') return false;
            row++; col--;
        }
        return true;
    }

    int findAns(int n, vector<string>& ans, int col) {
        if(col == n) return 1;

        int cnt = 0;
        for(int row=0; row<n; row++) {
            if(isSafe(row, col, ans, n)) {
                ans[row][col] = 'Q';
                cnt += findAns(n, ans, col+1);
                ans[row][col] = '.';  // Backtrack
            }
        }
        return cnt;
    }
public:
    int totalNQueens(int n) {
        vector<string> ans(n, string(n, '.'));
        int count = findAns(n, ans, 0);
        return count;
    }
};

