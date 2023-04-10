// let y/2 = x, so no.of set bits y - no.of set bits x <= 1;
// subproblem : no.of set bits i -> arr[i];
// relation arr[i] = arr[i/2] +  
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        for(int i = 1; i<=n; i++){
            ans[i] = ans[i/2] + i%2;
        }
        return ans;
    }
};