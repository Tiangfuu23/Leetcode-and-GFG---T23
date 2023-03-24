class Solution {
public:
    void gen(int k, int n, vector<vector<int>>& res, vector<int> temp, vector<int>&nums){
        if(k==n){
            res.push_back(temp);
        }else{
            temp.push_back(nums[k]);
            gen(k+1,n,res,temp,nums);
            temp.pop_back();
            while(k+1 < n && nums[k] == nums[k+1]) k++;
            gen(k+1,n,res,temp,nums);
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> temp;
        gen(0,nums.size(),res,temp,nums);
        return res;
    }
};