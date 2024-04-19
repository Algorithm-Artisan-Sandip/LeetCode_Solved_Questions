class Solution {
public:
    int mySqrt(int num) {
        int start = 0, end = num, ans = -1;
        while(start<=end){
            long long int mid = start + (end-start)/2;
            if(mid*mid == num) return mid;
            else if(mid*mid < num){
                ans = mid;
                start = mid+1;
            }
            else end = mid-1;
        }
        return ans;
    }
};