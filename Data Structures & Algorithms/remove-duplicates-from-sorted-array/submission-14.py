class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        k = 1 # number of unique elements(k) set to 1 since first value will always be unique

        for i in range(1, len(nums)): # starting range at 1 since we already know first value is unique
            if nums[i] != nums[i - 1]:
                nums[k] = nums[i] # The k index keeps track of the last known value that is unique
                k = k + 1 # Increasing by one in case there is another new unique value 
        return k

