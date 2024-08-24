class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> mapping;
        int size = s.size();
        for(int i=0; i<size; i++) {
            mapping[s[i]]++;
        }

        int count = mapping[s[0]];

        for(auto& t : mapping){
            if(count != t.second) return false;
        }
        return true;
    }
    
};