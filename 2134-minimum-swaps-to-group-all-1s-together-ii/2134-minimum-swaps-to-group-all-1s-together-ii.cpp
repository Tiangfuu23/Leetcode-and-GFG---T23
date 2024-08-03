class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size(), windowSize = 0;
        for(int num : nums) if(num) windowSize++;
        int cntOne = 0, max = 0;
        int l = 0, r = 0;
        for(int r = 0; r < 2*n; r++){
            cntOne += nums[r%n];
            if(r-l+1 > windowSize){
                cntOne-= nums[l%n];
                l+=1;
            }
            max = fmax(cntOne, max);
        }
        return windowSize - max;
    }
};