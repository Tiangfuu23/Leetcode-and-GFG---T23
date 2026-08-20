class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> set;
        int sum = 0;
        vector<int> ans;
        for(int& i : nums){
            if(set.find(i) == set.end()){
                sum += i;
                set.insert(i);
            }else{
                ans.push_back(i);
            }
        }
        int missing = (nums.size() * (nums.size() + 1) / 2) - sum;
        ans.push_back(missing);
        return ans;
    }
};