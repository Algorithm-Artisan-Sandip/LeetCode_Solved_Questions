class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long ans = 0, val = 1;
        vector<int> arr(n, 0);
        for (auto road : roads) {
            arr[road[0]]++;
            arr[road[1]]++;
        }
        sort(arr.begin(), arr.end());
        for (auto temp : arr) ans += temp * (val++);
        return ans;
    }
};