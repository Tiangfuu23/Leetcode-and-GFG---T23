public class Solution {
    public int MinSwaps(int[] nums) {
        int n = nums.Length;
        int windowSize = nums.Count(num => num == 1);
        int l = 0, r = 0, counter = 0, max = 0;
        
        for(; r < 2*n; r++){
            counter += nums[r%n];
            if(r - l + 1 > windowSize){
                counter -= nums[l%n];
                l++;
            }
            
            max = Math.Max(counter, max);
        }
        
        return windowSize - max;
    }
}