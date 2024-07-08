class Solution {
public:
    void findAndDel(queue<int>& q, int k) {
        for(int i=0; i <k-1; i++) {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
        q.pop();
    }
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i=0; i<n; i++) {
            q.push(i+1);
        }
        while(q.size()>1) {
            findAndDel(q,k);
        }
        return q.front();
    }
};