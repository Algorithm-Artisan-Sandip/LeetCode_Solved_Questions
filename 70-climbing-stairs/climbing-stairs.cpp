class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
        int st1 = 1, st2 = 2;
        int curr;
        for(int i=3; i<=n; i++) {
            curr = st1 + st2;
            st1 = st2;
            st2 = curr;
        }
        return curr;
    }
};