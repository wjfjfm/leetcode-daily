class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        start = len(nums)
        end = -1
        for n,i in enumerate(nums):
            if i == target:
                start = min(start, n)
                end = max(end, n)
        
        if start == len(nums):
            start = -1

        return [start, end]

