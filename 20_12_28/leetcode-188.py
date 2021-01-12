from typing import List
from collections import defaultdict
class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        
                
                
def test_leetcode_188():
    solution = Solution()
    k = 2
    prices = [2, 4, 1]
    assert(solution.maxProfit(k, prices) == 2)

    k = 2
    prices = [3, 2, 6, 5, 0, 3]
    assert(solution.maxProfit(k, prices) == 7)
