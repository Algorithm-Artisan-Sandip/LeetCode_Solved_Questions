/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Map to store mapping from original node to its clone
        unordered_map<Node*, Node*> mp;
        Node* temp = head;
        // Step 1: Create clone nodes and store in map
        while(temp) {
            // Clone the current node
            mp[temp] = new Node(temp->val);
            temp = temp->next;
        }
        temp = head;
        // Step 2: Assign next and random pointers to cloned nodes
        while(temp) {
            // Clone's next = clone of original's next
            mp[temp]->next = mp[temp->next];
            // Clone's random = clone of original's random
            mp[temp]->random = mp[temp->random];   
            temp = temp->next;
        }
        // Step 3: Return head of cloned linked list
        return mp[head];
    }
};