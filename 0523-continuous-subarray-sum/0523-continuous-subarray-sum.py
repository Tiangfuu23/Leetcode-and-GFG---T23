class Solution(object):
    def checkSubarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        prefixSum = [0]*len(nums)
        prefixSum[0] = nums[0];
        mp = {prefixSum[0]%k: 0}; # mod -> index
        for i in range(1,len(nums)):
            prefixSum[i] = prefixSum[i-1]+nums[i];
        for i in range(1,len(prefixSum)):
            if(prefixSum[i]%k==0):
                return True
            mod = prefixSum[i]%k
            if(mod in mp and i - mp[mod] > 1):
                return True
            if(mod not in mp):
                mp[mod] = i
        return False