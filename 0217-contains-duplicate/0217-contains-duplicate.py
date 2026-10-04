class Solution:
    def containsDuplicate(self, nums: list[int]) -> bool:
        dict={}
        for x in nums:
            dict[x]=dict.get(x,0)+1
            if dict[x]>1 :
                return True
        return False