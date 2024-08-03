class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size(), windowSize = 0;
        for(int num : nums) if(num) windowSize++;
        int cntOne = 0, max = 0;
        int l = 0, r = 0;
        while(r < windowSize) {
            if(nums[r]) cntOne++;
            r++;
        };
        while(r < 2*n){
            if(nums[r%n]) cntOne++;
            if(nums[l%n]) cntOne--;
            max = fmax(max,cntOne);
            l++; r++;
        }
        return windowSize - max;
    }
};