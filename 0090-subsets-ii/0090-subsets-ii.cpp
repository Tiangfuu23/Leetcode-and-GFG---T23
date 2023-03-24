class Solution {
private:
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> temp;
        int n = nums.size();
        vector<vector<int>> ans,res;
        for(int i = 0; i<(1<<n); i++){
            vector<int> subset;
            for(int j = 0; j<n; j++){
                if(i&(1<<j)) subset.push_back(nums[j]);
            }
            res.push_back(subset);
        }
        for(auto v : res){
            sort(v.begin(), v.end());
            if(temp.find(v) != temp.end()) continue;
            ans.push_back(v);
            temp.insert(v);
        }
        return ans; 
    }
};