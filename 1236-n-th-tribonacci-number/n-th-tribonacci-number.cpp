class Solution {
public:
    int tribonacci(int n) {
        if(n<=1) return n;
        if(n==2) return 1;
        int val1 = 0, val2 = 1, val3 = 1;
        int curr = 0;
        for(int i=3; i<=n; i++) {
            curr = val1 + val2 + val3;
            val1 = val2; 
            val2 = val3;
            val3 = curr;
        }
        return curr;
    }
};