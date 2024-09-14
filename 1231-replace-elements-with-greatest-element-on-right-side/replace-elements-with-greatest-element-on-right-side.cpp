class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int size = arr.size();
        int maxi = arr[size-1];
        int var = arr[size-1];
        arr[size-1] = -1;
        
        for(int i=size-2; i>=0; i--) {
            int temp = arr[i+1];
            maxi = max(maxi, var);
            var = arr[i];
            arr[i] = maxi;
        }

        return arr;
    }
};