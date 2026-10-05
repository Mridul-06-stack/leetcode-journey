class Solution:
    def rotate(self, nums: list[int], k: int) -> None:
        nums.reverse()
        k=k%len(nums)
        nums[:k]=nums[:k][::-1]
        nums[k:]=nums[k:][::-1]
        return nums
    
        """
        Do not return anything, modify nums in-place instead.
        """
        