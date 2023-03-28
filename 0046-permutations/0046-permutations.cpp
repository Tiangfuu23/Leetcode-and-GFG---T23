class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> h(n);
        vector<vector<int>> res;
        vector<int> temp(n);
        for(int i=0; i<n; i++) h[i] = i;
        do{
            for(int i = 0; i<n; i++){
                temp[i] = nums[h[i]];
            }
            res.push_back(temp);
        }while(next_permutation(h.begin(), h.end()));
        return res;
    }
};