# nums = [1, -1, 0] k = 0
# prefixSum = [0, 1, 0, 0]

class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        cnt = 0
        
        hashmap = {}
        hashmap[0] = 1
        
        prefixSum = [0]
        for val in nums:
            prefixSum.append(prefixSum[-1] + val)
        
        for i in range(1, len(prefixSum)):
            if prefixSum[i] - k in hashmap:
                cnt += hashmap[prefixSum[i] - k]
            hashmap[prefixSum[i]] = hashmap[prefixSum[i]] + 1 if(prefixSum[i]in hashmap) else 1
        return cnt
            