from typing import List
class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        def find(a, ufs):
            while(ufs.get(a) is not None):
                ufs[a] = find(ufs[a], ufs)
                return ufs[a]
            return a

        def union(a, b, ufs):
            if find(a, ufs) != find(b, ufs):
                ufs[find(a, ufs)] = find(b, ufs)
                return find(a, ufs)

        ufs = {}
        for item in edges:
            if find(item[0], ufs) == find(item[1], ufs):
                return item
            else:
                union(item[0], item[1], ufs)


def test_leetcode_684():
    solution = Solution()
    edges = [[1, 2], [1, 3], [2, 3]]
    answer = [2, 3]
    assert solution.findRedundantConnection(edges) == answer

    edges = [[1,2], [2,3], [3,4], [1,4], [1,5]]
    answer = [1, 4]
    assert solution.findRedundantConnection(edges) == answer
