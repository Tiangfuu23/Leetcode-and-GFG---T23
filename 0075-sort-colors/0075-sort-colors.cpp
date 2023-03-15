class Solution {
public:
    void sortColors(vector<int>& nums) {
        int h[3] ={0}; // frequencies of i = 0,1,2
        for(int i : nums) h[i]++;
        int j = 0;
        for(int i = 0; i<=2; i++){
            while(h[i]!=0){
                nums[j] = i;
                h[i]--;
                j++;
            }
        }
    }
};