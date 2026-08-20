class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<bool> isExisted(nums.size());
        for(int& i : nums){
            isExisted[i-1] = true;
        }

        vector<int> ans;
        for(int i = 0; i < isExisted.size(); i++){
            if(!isExisted[i])
                ans.push_back(i+1);
        }

        return ans;
    }
};