// subproblem : Total # of ways that make up sum(x) at first k value in coins 
// relation (guessing) : containe k + !containe k 
// ---> sum_k(x) = sum_k(x-k) + sum_(k-1)(x) 
// base case sum_k(0) = 1 with k in coins
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp (n,vector<int> (amount+1,0));
        for(int i = 0; i<n; i++) dp[i][0] = 1;
        for(int i = 0; i<n; i++){
            for(int j = 1; j<=amount; j++){
                int val = coins[i];
                if(j-val>=0){
                    dp[i][j] += dp[i][j-val]; // containe val 
                }    
                dp[i][j] += i-1>=0 ? dp[i-1][j] : 0; // does not containe val
            }
        }
    return dp[n-1][amount];
    }
};