class Solution {
private:
    int nCr(int n, int r) {
        // if(r>n-r) r = n-r;
        long long res = 1;

        // e.g.,
        // 10C3 = 10! / (3! * (10-3)!)
        //      = 10*9*8 / 3!
        //      = (10/1)*(10/2)*(10/3)

        for(int i=0; i<r; i++) {
            res = res*(n-i);
            res = res/(i+1);
        }

        return res;
    }
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal(numRows);

        for(int i=0; i<numRows; i++) {
            pascal[i].resize(i+1);
            for(int j=0; j<i+1; j++) {
                pascal[i][j] = nCr(i,j);
            }
        }

        return pascal;
    }
};