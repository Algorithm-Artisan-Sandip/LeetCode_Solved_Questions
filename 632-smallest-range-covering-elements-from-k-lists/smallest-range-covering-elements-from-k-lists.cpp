class Info {
public:
    int data;
    int rowIdx;
    int colIdx;

    Info(int a, int b, int c) {
        this->data = a;
        this->rowIdx = b;
        this->colIdx = c;
    }
};

// Comparator:
class compare {
public:
    bool operator()(Info* a, Info* b) {
        return a->data > b->data;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Info*, vector<Info*>, compare> pq;
        int maxi = INT_MIN;

        // Processing the first elements of k lists:
        for(int i = 0; i < nums.size(); i++) {
            int element = nums[i][0];
            Info* temp = new Info(element, i, 0);
            pq.push(temp);
            maxi = max(maxi, element);
        }

        int ansStart = pq.top()->data;
        int ansEnd = maxi;

        while(!pq.empty()) {
            Info* topNode = pq.top();
            pq.pop();

            int mini = topNode->data;
            int topRow = topNode->rowIdx;
            int topCol = topNode->colIdx;

            // Compare to get the smaller range:
            if((maxi - mini) < (ansEnd - ansStart)) {
                ansStart = mini;
                ansEnd = maxi;
            }

            // Insertion:
            if(topCol + 1 < nums[topRow].size()) {
                int newElement = nums[topRow][topCol + 1];
                maxi = max(maxi, newElement);
                Info* newInfo = new Info(newElement, topRow, topCol + 1);
                pq.push(newInfo);
            }
            // No elements left in this row:
            else {
                break;
            }
        }

        return {ansStart, ansEnd};
    }
};
