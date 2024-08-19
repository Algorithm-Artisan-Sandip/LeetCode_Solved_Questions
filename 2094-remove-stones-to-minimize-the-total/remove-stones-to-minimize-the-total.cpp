class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> maxHeap;

        for(auto& pile : piles) {
            maxHeap.push(pile);
        }

        while(k--) {
            int temp = maxHeap.top();
            maxHeap.pop();
            temp = temp-temp/2;
            maxHeap.push(temp);
        }

        int sum = 0;
        while(!maxHeap.empty()) {
            sum += maxHeap.top();
            maxHeap.pop();
        }

        return sum;
    }
};