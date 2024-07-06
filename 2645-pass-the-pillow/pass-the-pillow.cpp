class Solution {
public:
    int passThePillow(int n, int time) {
        int x = time / (n-1);
        int y = time % (n-1);
        if(x&1) return n-y;
        else return 1+y;
    }
};