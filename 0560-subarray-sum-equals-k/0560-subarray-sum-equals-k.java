class Solution {
    public int subarraySum(int[] nums, int k) {
        int[] prefixSum = new int[nums.length];
        prefixSum[0] = nums[0];
        for(int i = 1; i<nums.length; i++){
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }
        HashMap<Integer, Integer> mp = new HashMap<>();
        mp.put(0,1);
        int ans = 0;
        for(int val : prefixSum){
            int remain = val - k;
            if(mp.containsKey(remain)){
                ans += mp.get(remain);
            }
            if(mp.containsKey(val)){
                mp.put(val, mp.get(val)+1);
            }else{
                mp.put(val, 1);
            }
        }
        return ans;
    }
}