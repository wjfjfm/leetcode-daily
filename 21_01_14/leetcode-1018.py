from typing import List
class Solution:
    def prefixesDivBy5(self, A: List[int]) -> List[bool]:
        result = []
        num = 0
        for i in A:
            num = num * 2 + i
            if num % 5 == 0:
                result.append(True)
            else:
                result.append(False)
        return result


def test_leetcode_1018():
    solution = Solution()
    A = [0, 1, 1]
    answer = [True, False, False]
    assert solution.prefixesDivBy5(A) == answer
