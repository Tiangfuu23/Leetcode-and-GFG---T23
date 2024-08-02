class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n+1, true);
        int compNumCnt = n > 1 ? 2 : n;
        for(int i = 2; i*i < n; i++){
            if(!isPrime[i]) continue;
            for(int j = i*i; j<n; j+=i){
                if(isPrime[j]) compNumCnt++;
                isPrime[j] = false;
            }
        }
        return n - compNumCnt;
    }
};