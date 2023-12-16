class Solution(object):
    def checkSubarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        mp = {nums[0]%k: 0}; # mod -> index
        s = nums[0]
        for i in range(1,len(nums)):
            s += nums[i]
            if(s%k==0):
                return True
            mod = s%k
            if(mod in mp and i - mp[mod] > 1):
                return True
            if(mod not in mp):
                mp[mod] = i
        return False