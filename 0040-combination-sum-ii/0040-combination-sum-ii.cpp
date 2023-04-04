class Solution {
private:
    vector<vector<int>> ans;
    vector<int> temp;
    int sum = 0;
    int prev = -1;
public:
    void search(vector<int>& nums, int target, int k){
        if(sum == target){
            ans.push_back(temp);
        }else if(sum < target){
            for(int i = k; i<nums.size(); i++){
                if(nums[i] == prev) continue;
                else prev = -1;
                sum += nums[i];
                temp.push_back(nums[i]);
                search(nums,target,i+1);
                prev = temp[temp.size() - 1];
                temp.pop_back();
                sum -= nums[i];
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        search(candidates,target,0);
        return ans;
    }
};