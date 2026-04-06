class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        if len(set(nums)) < len(nums): # set can't have duplicates 
            return True 
        else:
            return False
            