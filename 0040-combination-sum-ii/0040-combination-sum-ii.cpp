class Solution {
public:
    void search(vector<vector<int>>& ans, vector<int>& temp, vector<int>& nums, int target, int index){
        if(target == 0){
            ans.push_back(temp);
        }else if(target > 0){
            for(int i = index; i<nums.size(); i++){
                if(i>index && nums[i] == nums[i-1]) continue;
                temp.push_back(nums[i]);
                search(ans,temp,nums,target-nums[i],i+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        search(ans,temp,candidates,target,0);
        return ans;
    }
};