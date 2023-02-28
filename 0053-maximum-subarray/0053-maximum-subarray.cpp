class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n); 
        pref[0] = nums[0];
        for(int i = 1; i<n; i++) pref[i] = pref[i-1] + nums[i];
        int max_sub_arr = pref[0]; int min_sub_arr = 0;
        for(int i=0; i<n; i++){
            max_sub_arr = max(max_sub_arr,pref[i] - min_sub_arr);
            min_sub_arr = min(min_sub_arr,pref[i]);
        }
        return max_sub_arr;
    }
};
// [-1,1]
// [-1,0]