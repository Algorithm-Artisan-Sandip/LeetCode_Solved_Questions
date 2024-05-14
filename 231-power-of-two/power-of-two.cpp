class Solution {
public:
    int powTwo(long long int n, long long int two) {
        if(n==two) return 1;
        else if(n<two) return 0;
        else {
            two = two * 2;
            return powTwo(n, two);
        }
    }
    bool isPowerOfTwo(long long int n) {
        if(n<=0) return false;
        else if(n==1) return true;
        else {
            return powTwo(n, 2);
        }
        
        return 0;
    }
};