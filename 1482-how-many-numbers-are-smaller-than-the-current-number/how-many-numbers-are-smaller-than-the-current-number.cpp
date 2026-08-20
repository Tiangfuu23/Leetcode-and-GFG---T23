class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> cnt(101);
        for(int& i : nums){
            cnt[i]++;
        }
        for(int i = 1; i <101; i++){
            cnt[i] = cnt[i-1] + cnt[i];
        }

        vector<int> ans(nums.size());
        for(int i = 0; i<nums.size(); i++){
            ans[i] = nums[i] == 0 ? 0 : cnt[nums[i]-1];
        }

        return ans;
    }
};