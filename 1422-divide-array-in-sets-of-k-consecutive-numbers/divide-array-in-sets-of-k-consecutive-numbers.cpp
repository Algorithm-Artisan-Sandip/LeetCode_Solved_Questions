class Solution {
public:
    bool isPossibleDivide(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }

        map<int, int> count;
        for (int card : hand) {
            count[card]++;
        }

        for (auto it = count.begin(); it != count.end(); ++it) {
            int currentCard = it->first;
            int occurrences = it->second;

            if (occurrences > 0) {
                for (int i = 1; i < groupSize; i++) {
                    int nextCard = currentCard + i;
                    if (count[nextCard] < occurrences) {
                        return false; 
                    }
                    count[nextCard] -= occurrences;
                }
                count[currentCard] = 0; 
            }
        }
        
        return true;
    }
};