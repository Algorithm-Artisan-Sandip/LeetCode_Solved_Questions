// JOSEPHUS Problem : 

// Approach 1 :

// class Solution {
// public:
//     void findAndDel(queue<int>& q, int k) {
//         for(int i=0; i <k-1; i++) {
//             int temp = q.front();
//             q.pop();
//             q.push(temp);
//         }
//         q.pop();
//     }
//     int findTheWinner(int n, int k) {
//         queue<int> q;
//         for(int i=0; i<n; i++) {
//             q.push(i+1);
//         }
//         while(q.size()>1) {
//             findAndDel(q,k);
//         }
//         return q.front();
//     }
// };

// Approach 2 : 

class Solution {
public:
    int findAndDel(int n, int k) {
        // base case : at last one element remains so return the index of the element
        if(n==1) {
            return 0;
        }
        
        else {
            return (findAndDel(n-1,k)+k) % n;  // most important => after each operation one element will be deleted(so n-1) and the couning will start after the kth person(so +k) and to maintain the circular nature %n.
        }
    }
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i=0; i<n; i++) {
            q.push(i+1);
        }
        return findAndDel(n,k) + 1;
    }
};
