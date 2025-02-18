class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int cnt = 0;
        int j = 0;
        for(int i=0; i<arr.size(); i++) {
            j++;
            while(j != arr[i]) {
                cnt++;
                if(cnt == k) return j;
                j++;
            }
        }
        return j + (k-cnt);
    }
};