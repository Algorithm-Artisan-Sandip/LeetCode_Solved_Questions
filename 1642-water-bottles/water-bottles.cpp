class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drink = numBottles;
        while(numBottles >= numExchange){
            int full = numBottles / numExchange;
            int empty = numBottles % numExchange;
            drink += full;
            numBottles = full + empty;
        }
        return drink;
    }
};