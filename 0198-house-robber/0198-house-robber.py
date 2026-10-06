class Solution:
    def rob(self, nums: list[int]) -> int:
        dp=[-1]*len(nums)
        def helper(idx,nums):
            if(idx==0):
                return nums[idx]
            if(idx<0):
                return 0
            if dp[idx]!=-1:
                return dp[idx]
            rob=nums[idx]+helper(idx-2,nums)
            notrob=helper(idx-1,nums)
            dp[idx]=max(rob,notrob)
            return dp[idx]
        
        return helper(len(nums)-1,nums)
            

        