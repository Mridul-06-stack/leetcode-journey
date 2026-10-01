class Solution:
    def majorityElement(self, nums: list[int]) -> list[int]:
         dict={}
         ans=[]
         n=len(nums)
         for i,x in enumerate(nums):
            dict[x]=1+dict.get(x,0)
            if dict[x] >n/3 and x not in ans:
                ans.append(x)
         return ans