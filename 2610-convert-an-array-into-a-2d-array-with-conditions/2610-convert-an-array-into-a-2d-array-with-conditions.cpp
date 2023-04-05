class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<unordered_set<int>> row;
        vector<vector<int>> ans;
        for(int num : nums){
            bool exist = false;
            for(int i = 0; i<row.size(); i++){
                unordered_set<int>& st = row[i];
                if(st.find(num) == st.end()){
                    ans[i].push_back(num);
                    st.insert(num);
                    exist = true;
                    break;
                }
            }
            if(exist) continue;
            row.push_back({num});
            ans.push_back({num});
        }
        return ans;
    }
};