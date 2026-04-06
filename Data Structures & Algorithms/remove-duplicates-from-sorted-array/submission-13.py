class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        k = 1 # number of unique elements(k) set to 1 since first value will always be unique

        for i in range(1, len(nums)): # starting range at 1 since we already know first value is unique
            if nums[i] != nums[i - 1]:
                nums[k] = nums[i]
                k = k + 1
        return k

