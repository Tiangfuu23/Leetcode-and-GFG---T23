class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        vector<int> aws;
        for(int i = 0; i<nums.size(); i++){
            int current_value = nums[i];
            int differ = target - current_value;
            if(mp.count(differ)){
                aws.push_back(mp[differ]);
                aws.push_back(i);
                return aws;
            }else{
                mp.insert({current_value,i});
            }
        }
        return aws;
    }
};