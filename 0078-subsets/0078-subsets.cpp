class Solution {
public:
    // time O(2^n)
    // gerateing
    void gen(int k, int n, vector<vector<int>>& res, vector<int> temp, vector<int>& nums){
        if(k==n){
            // goal
            res.push_back(temp);
        }else{
            //choice - no constraint
            gen(k+1,n,res,temp,nums);
            temp.push_back(nums[k]);
            gen(k+1,n,res,temp,nums);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> res;
        int n = nums.size(), k = 0;
        gen(k,n,res,temp,nums);
        return res;
    }
};