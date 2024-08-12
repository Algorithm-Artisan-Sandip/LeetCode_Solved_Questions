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

class compare {
public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        // Process the first element of every Linked List
        for(int i = 0; i < lists.size(); i++) {
            ListNode* listHead = lists[i];
            if(listHead != nullptr) {
                pq.push(listHead);
            }
        }

        // If the priority queue is empty, return NULL
        if (pq.empty()) return nullptr;

        // New Linked List
        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        while(!pq.empty()) {
            ListNode* topNode = pq.top();
            pq.pop();

            // If the new linked list is empty, initialize it with the topNode
            if(head == nullptr) {
                head = topNode;
                tail = topNode;
            } else {
                // Append the current node to the new linked list
                tail->next = topNode;
                tail = topNode;
            }

            // If there's a next node in the current list, push it into the priority queue
            if(topNode->next != nullptr) {
                pq.push(topNode->next);
            }
        }

        return head;
    }
};
