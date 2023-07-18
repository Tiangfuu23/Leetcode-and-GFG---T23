class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int max = INT_MIN, n = nums.size();
        for(int i = 0; i<n-2;i++){
            max = fmax(nums[i],max);
            if(max>nums[i+2]) return false;
        }
        return true;
    }
};