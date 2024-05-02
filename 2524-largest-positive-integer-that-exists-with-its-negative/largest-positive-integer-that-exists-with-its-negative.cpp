class Solution {
public:
    int findMaxK(vector<int>& nums) {
        vector<int> posArr, negArr;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0)
                posArr.push_back(nums[i]);
            else if (nums[i] < 0)
                negArr.push_back(nums[i]);
        }

        sort(posArr.begin(), posArr.end());

        sort(negArr.begin(), negArr.end(), greater<int>());

        int max = -1;

        for (int i = 0, j = 0; i < posArr.size() && j < negArr.size();) {

            if (posArr[i] < abs(negArr[j])) {
                i++;
            }
            else if (posArr[i] > abs(negArr[j])) {
                j++;
            }
            else if (posArr[i] == abs(negArr[j])) {
                max = posArr[i];
                i++;
                j++;
            }
        }

        return max; 
    }
};