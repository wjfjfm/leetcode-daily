from typing import List
from collections import defaultdict
class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
        def getminSubArray(nums, i):
            start = nums.index(i)
            end = nums[::-1].index(i)
            return len(nums) - end - start

        numdict = defaultdict(int)
        for i in nums:
            numdict[i] += 1
        maxcount = 0
        maxnum = []
        for item in numdict.items():
            if item[1] > maxcount:
                maxcount = item[1]
                maxnum = []
                maxnum.append(item[0])
            elif item[1] == maxcount:
                maxnum.append(item[0])
        result = 2e30
        for i in maxnum:
            tmp = getminSubArray(nums, i)
            if tmp < result:
                result = tmp
        return result

def test_leetcode_697():
    solution = Solution()
    nums = [1, 2, 2, 3, 1]
    assert solution.findShortestSubArray(nums) == 2
    nums = [1,2,2,3,1,4,2]
    assert solution.findShortestSubArray(nums) == 6

