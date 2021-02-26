from typing import List
from collections import defaultdict
class Solution:
    def findNumOfValidWords(self, words: List[str], puzzles: List[str]) -> List[int]:
        puzzle_set = defaultdict(set)
        for i in puzzles:
            for j in range(len(i)):
                puzzle_set[i[j]].add(i)
        answer = defaultdict(int)
        for i in words:
            canbe = set(puzzles)
            for j in range(len(i)):
                canbe = canbe & puzzle_set[i[j]]
            for j in canbe:
                if j[0] in i:
                    answer[j] += 1
        result = [answer[i] for i in puzzles]
        return result

def test_leetcode_1178():
    solution = Solution()
    words = ["aaaa","asas","able","ability","actt","actor","access"]
    puzzles = ["aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"]
    answer = [1,1,3,2,4,0]
    assert solution.findNumOfValidWords(words, puzzles) == answer

