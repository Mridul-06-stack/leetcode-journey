class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
       
        dict={}
        for i,x in   enumerate(nums):
            dict[x]=i

        for i,x in enumerate(nums):
            remaining=target-x
            if remaining in dict and i!=dict[remaining]:
                  return [i,dict[remaining]]    
        return []
