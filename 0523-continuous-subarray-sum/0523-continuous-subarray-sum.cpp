// [5,0,0,0]
// [5,5,5,5]
// mp = 2,0 
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<int> prefixSum(nums.size(), 0);
        prefixSum[0] = nums[0];
        for(int i = 1; i<nums.size(); i++){
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }
        mp.insert({prefixSum[0]%k,0});
        for(int i = 1; i<prefixSum.size(); i++){
            if(prefixSum[i]%k==0) return true;
            int mod = prefixSum[i]%k;
            if(mp.count(mod) && i - mp[mod] > 1) return true;
            if(!mp.count(mod)){
                mp[mod] = i;
            }
        }
        return false;
    }
};