class Solution {
private:
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> temp;
        int n = nums.size();
        for(int i = 0; i<(1<<n); i++){
            vector<int> subset;
            for(int j = 0; j<n; j++){
                if(i&(1<<j)) subset.push_back(nums[j]);
            }
            sort(subset.begin(), subset.end());
            temp.insert(subset);;
        }
        vector<vector<int>> res;
        for(auto i : temp) res.push_back(i);
        return res; 
    }
};