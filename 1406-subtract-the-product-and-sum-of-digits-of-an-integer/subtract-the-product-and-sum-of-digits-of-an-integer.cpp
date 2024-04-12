class Solution {
public:
    int subtractProductAndSum(int n) {
        long long int multi = 1;
        long long int sum = 0;

        while(n>0){
            sum+=n%10;
            multi*=n%10;
            n/=10;
        }
        return multi-sum;
    }
};