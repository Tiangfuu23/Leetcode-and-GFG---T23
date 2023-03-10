class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> len(n,1);
        int ans = 1;
        for(int i = 1; i<n; i++){
            for(int j = 0; j<i; j++){
                if(nums[j] < nums[i]){
                    len[i] = fmax(len[i],len[j]+1);
                }
            }
            ans = fmax(len[i],ans);
        }
    return ans;
    }
};