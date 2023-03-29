class Solution {
private:
    unordered_map<int,int> mp;
    vector<int> permutation;
    vector<vector<int>> res;
public:
    void search(int n){
        if(permutation.size() == n){
            res.push_back(permutation);
        }else{
            for(auto& i : mp){
                if(i.second > 0){
                    permutation.push_back(i.first);
                    i.second--;
                    search(n);
                    i.second++;
                    permutation.pop_back();
                }
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        for(auto i : nums) mp[i]++;
        search(nums.size());
        return res;
    }
};