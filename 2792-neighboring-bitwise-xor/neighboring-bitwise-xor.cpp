class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int check = 0;
        for(int i=0; i<derived.size(); i++) check^=derived[i];
        if(check==0) return true;
        else return false;
    }
};