// DP solution 
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> ans (amount+1,INT_MAX);
        ans[0] = 0;
        for(int i =1; i<=amount; i++){
            for(int& c: coins){
                if(i-c>=0 && ans[i-c] != INT_MAX){
                    ans[i] = fmin(ans[i], 1 + ans[i-c]);
                }
            }
        }
        return ans[amount] != INT_MAX ? ans[amount] : -1;
    }
};