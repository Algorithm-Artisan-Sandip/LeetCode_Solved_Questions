class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > bloomDay.size()) return -1;
        int l = 1, h = 1e9;
        while (l < h) {
            int mid = l + (h - l) / 2;
            if (canMakeBouquets(bloomDay, m, k, mid)) h = mid;
            else l = mid + 1;
        }
        return l;
    }

private:
    bool canMakeBouquets(const vector<int>& bloomDay, int m, int k, int day) {
        int bouquets = 0, flowers = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0; // Reset flower count for next bouquet
                }
            } else {
                flowers = 0; // Reset flower count if the current bloomDay is greater than day
            }
            if (bouquets >= m) return true;
        }
        return false;
    }
};
