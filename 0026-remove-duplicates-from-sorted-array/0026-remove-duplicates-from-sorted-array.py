class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
            s=set(nums)
            st=sorted(s)
            i=0
            for x in st:
                nums[i]=x
                i+=1
            return len(st)