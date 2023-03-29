class Solution {
private:
    vector<int> temp;
    vector<vector<int>> ans;
    int sum = 0;
public:
    void search(int k,int target, vector<int>& candidates){
        int n = candidates.size();
        if(sum == target){
            ans.push_back(temp);
        }else if(sum > target){
            return;
        }else{
            for(int i = k; i<n; i++){
                temp.push_back(candidates[i]);
                sum += candidates[i];
                search(i,target,candidates);
                sum -= candidates[i];
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        search(0,target,candidates);
        return ans;
    }
};