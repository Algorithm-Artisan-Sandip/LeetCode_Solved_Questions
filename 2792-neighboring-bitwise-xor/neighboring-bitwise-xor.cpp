class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {

        int check = 0;

        for(int i : derived) check ^= i;

        return check==0;
    }
};