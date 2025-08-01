class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int cnt = 0;
        for(int i=0; i<fruits.size(); i++) {
            bool flag = true;
            for(int j=0; j<baskets.size(); j++) {
                if(fruits[i] <= baskets[j]) {
                    baskets[j] = 0;
                    fruits[i] = 0;
                    flag = false;
                    break;
                }
            }
            if(flag) cnt++;
        }
        return cnt;
    }
};