/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
int findLength(ListNode* head) {
    ListNode* temp = head;
    int count = 0;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(findLength(head) < 4) return {-1,-1};
        
        vector<int> criticalPoints;
        int position = 1;
        ListNode* temp = head;

        while(temp->next != NULL && temp->next->next != NULL) {
            ListNode* temp1 = temp->next;
            ListNode* temp2 = temp1->next;
            if((temp->val > temp1->val && temp2->val> temp1->val) ||
            (temp->val < temp1->val && temp2->val < temp1->val)) {
                criticalPoints.push_back(position+1);
            }
            position++;
            temp = temp->next;
        }
        if(criticalPoints.size()<2) return {-1,-1};
        else {
            int minDist = INT_MAX;
            for(int i=1; i<criticalPoints.size(); i++) {
                minDist = min(minDist, criticalPoints[i]-criticalPoints[i-1]);
            }
            int maxDist = criticalPoints[criticalPoints.size()-1] - criticalPoints[0];
            return {minDist,maxDist};
        }
    }
};