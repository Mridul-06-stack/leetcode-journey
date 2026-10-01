class Solution:
    def maxSubArray(self, nums: list[int]) -> int:
        sum=nums[0]
        maxsum=nums[0]
        for x in nums[1:]:
           sum=max(x,sum+x)
           maxsum=max(sum,maxsum)
        return maxsum    