// time O(n) space O(1) solution
// not that ans belongs to [1,.....len(nums) + 1]
class Solution {
public:
    bool isSafe(int i, int n){
        return i<=n && i>=1;
    }
    int firstMissingPositive(vector<int>& nums) {
        int n =  nums.size();
        // get rid of negetive number
        for(auto& i : nums) if(i<0) i = 0;
        // in-place hashing 
        for(int i : nums){
            i = abs(i);
            if(isSafe(i,n)){
                if(nums[i-1] == 0){
                    nums[i-1] = -(n+1);
                }else{
                    nums[i-1] = -abs(nums[i-1]);
                }
            }
        }
        // find ans
        int ans =  1;
        for(; ans<=n; ans++) if(nums[ans-1] >= 0) return ans;
        return ans;
    }
};