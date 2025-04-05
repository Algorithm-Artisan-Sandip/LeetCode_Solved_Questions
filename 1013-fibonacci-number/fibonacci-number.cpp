class Solution {
private:
    int fibnac(int n) {
        if(n<=1) return n;
        return fibnac(n-1) + fibnac(n-2);
    }
public:
    int fib(int n) {
        return fibnac(n);
    }
};