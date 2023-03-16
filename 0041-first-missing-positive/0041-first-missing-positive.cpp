// time O(nlogn) space O(1)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int ans = 1, n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i<n; i++){
            if(nums[i] <= 0) continue;
            else if(nums[i] == ans) ans++;
            else if(nums[i] > ans) return ans;
        }
        return ans;
    }
};