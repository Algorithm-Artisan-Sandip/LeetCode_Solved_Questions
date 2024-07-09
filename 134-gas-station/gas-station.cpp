class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size = gas.size();
        int start = 0;
        int balance = 0;
        int deficit = 0;

        for(int i=0; i<size; i++) {
            balance += gas[i] - cost[i];

            if(balance<0) {
                deficit += abs(balance);
                balance = 0;
                start = i+1;
            }
        }

        if(balance - deficit >= 0) return start;
        else return -1;
    }
};