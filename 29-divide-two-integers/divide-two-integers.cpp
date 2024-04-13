#include <climits> // for INT_MIN and INT_MAX

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle special cases
        if (divisor == 0) return INT_MAX;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        
        // Determine the sign of the quotient
        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
        
        // Convert dividend and divisor to positive numbers
        long long dvd = labs(dividend);
        long long dvs = labs(divisor);
        
        // Initialize quotient and temporary variables
        long long quotient = 0, temp = 0;
        
        // Perform long division
        for (int i = 31; i >= 0; --i) {
            if ((temp + (dvs << i)) <= dvd) {
                temp += (dvs << i);
                quotient |= 1LL << i;
            }
        }
        
        // Adjust sign of the quotient
        quotient = sign * quotient;
        
        // Handle overflow
        if (quotient > INT_MAX) return INT_MAX;
        if (quotient < INT_MIN) return INT_MIN;
        
        return quotient;
    }
};
