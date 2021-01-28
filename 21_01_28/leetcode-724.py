from typing import List
class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        left = 0
        right = len(nums)-1
        while(left <= right):
            m = int((left + right) / 2)
            sumleft = sum(nums[0:m])
            sumright = sum(nums[m+1:])
            print("m = ", m, "l, r = ", sumleft, ",", sumright)
            if sumleft < sumright:
                left = m + 1
            elif sumleft > sumright:
                right = m - 1
            elif sumleft == sumright:
                return m
        return -1


def test_leetcode_724():
    solution = Solution()
    nums = [1, 7, 3, 6, 5, 6]
    answer = 3
    assert solution.pivotIndex(nums) == answer

    nums = [1, 2, 3]
    answer = -1
    assert solution.pivotIndex(nums) == answer
