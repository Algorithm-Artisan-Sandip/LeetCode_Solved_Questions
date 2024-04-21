class Solution {
public:
    
    int countPrimes(int n) {
        int count = 0;
        if(n==0) return 0;
        vector<bool> prime(n,true);
        prime[0] = prime[1] = false;

        for(int i=2; i<n; i++){
            if(prime[i]){
                count++;
            
                int j=i;
                while(j<n){
                    prime[j] = false;
                    j+=i;
                }
            } 
        }
        return count;
    }
};
