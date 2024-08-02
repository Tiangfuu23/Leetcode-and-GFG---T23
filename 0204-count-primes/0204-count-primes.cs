// 2 -> 4 6 8 10 12
// 3 -> 9 12 
// 
public class Solution {
    public int CountPrimes(int n) {
        bool[] isPrime = new bool[n+1];
        Array.Fill(isPrime, true);
        int cntCompositeNumber = n > 1 ? 2 : n;
        for(int i = 2; i*i<n; i++){
            if(!isPrime[i]) continue;
            for(int j = i*i; j<n; j+=i){
                if(isPrime[j]) cntCompositeNumber++;
                isPrime[j] = false;
            }
        }
        return n - cntCompositeNumber;
    }
}