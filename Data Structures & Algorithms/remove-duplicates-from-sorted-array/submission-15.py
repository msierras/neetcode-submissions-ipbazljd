class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        k = 1 # since first value is unique by default

        for i in range(1, len(nums)):
            if(nums[k - 1] != nums[i]):
                k = k + 1
                nums[k - 1] = nums[i]
        return k

