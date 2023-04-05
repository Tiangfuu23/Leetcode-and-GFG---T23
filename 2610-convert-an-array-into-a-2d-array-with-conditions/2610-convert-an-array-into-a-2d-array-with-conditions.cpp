class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_map<int,int> mp; // value - frequency
        for(int i : nums) mp[i]++;
        while(mp.size()){
            // while map is not empty;
            vector<int> temp;
            for(auto i : mp) temp.push_back(i.first);
            for(auto i : temp) if(!--mp[i]) mp.erase(i);
            ans.push_back(temp);
        }
    return ans;
    }
};