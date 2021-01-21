from typing import List
class Solution:
    def maximumProduct(self, nums: List[int]) -> int:
        if len(nums) == 3:
            return nums[0] * nums[1] * nums[2]
        nums = sorted(nums)
        big = nums[-1]
        if big == 0:
            return 0
        elif big < 0:
            return nums[-1] * nums[-2] * nums[-3]
        pst = nums[-2] * nums[-3]
        result = 0
        if pst >= 0:
            result = max(result, big * pst)
        nst = nums[0] * nums[1]
        if nst >= 0:
            result = max(result, big * nst)
        return result


def test_leetcode_628():
    solution = Solution()
    nums = [5,6,7,-7,-8]
    answer = 7 * 7 * 8
    assert solution.maximumProduct(nums) == answer
    nums = [5, 6, 7, -3, -4]
    answer = 5 * 6 * 7
    assert solution.maximumProduct(nums) == answer


