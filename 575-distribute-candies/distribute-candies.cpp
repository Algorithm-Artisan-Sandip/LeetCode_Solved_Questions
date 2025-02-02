class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_map<int, int> freq;
        int size = candyType.size();
        for(int i=0; i<size; i++) {
            freq[candyType[i]]++;
        }
        int distinct = freq.size();
        if(distinct > size/2) return size/2;
        else return distinct;
    }
};