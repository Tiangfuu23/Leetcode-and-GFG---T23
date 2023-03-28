class Solution {
private:
    vector<vector<int>> res;
    vector<int> permutation;
    unordered_set<int> chosen;
public:
    void search(vector<int>& nums){
        int n = nums.size();
        if(permutation.size() == n){
            // goal
            res.push_back(permutation);
        }else{
            for(int i = 0; i<n; i++){
                int choice = nums[i];
                if(chosen.find(choice) != chosen.end()) continue;
                permutation.push_back(choice);
                chosen.insert(choice);
                search(nums);
                chosen.erase(choice);
                permutation.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        search(nums);
        return res;
    }
};