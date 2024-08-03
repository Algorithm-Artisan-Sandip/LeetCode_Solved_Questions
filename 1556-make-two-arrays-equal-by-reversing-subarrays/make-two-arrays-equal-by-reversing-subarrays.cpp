class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        int size = arr.size();
        for(int i=0; i< size; i++) {
            if(target[i] != arr[i]) return false;
        }
        return true;
    }
};