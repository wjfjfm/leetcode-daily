from typing import List
import copy
class Solution:
    def union(self, ufs, a, b):
        if self.find(ufs, a) != self.find(ufs, b):
            ufs[self.find(ufs, a)] = self.find(ufs, b)

    def find(self, ufs, a):
        if ufs.get(a) is not None:
            ufs[a] = self.find(ufs, ufs[a])
        else:
            return a
    def BFS(self, ufs, available_edges, used, no_cri):
        for n, i in enumerate(available_edges):
            if self.find(ufs, i[0]) == self.find(ufs, i[1]):
                no_cri.add(i[2])
                available_edges.remove(i)
                self.BFS(ufs, available_edges, used, no_cri)
                available_edges.insert(n, i)
            else:
                used.add(i[2])
                new_ufs = copy.deepcopy(ufs)
                self.union(new_ufs, i[0], i[1])
                available_edges.remove(i)
                self.BFS(new_ufs, available_edges, used, no_cri)
                available_edges.insert(n, i)

    def findCriticalAndPseudoCriticalEdges(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        ufs = {}
        used = set()
        no_cri = set()
        edges = [[i[2], i[1], i[0]] for i in edges ]
        reverse_edges.sort()

            
        return None


def test_leetcode_1489():
    solution = Solution()
    n = 5
    edges = [[0,1,1],[1,2,1],[2,3,2],[0,3,2],[0,4,3],[3,4,3],[1,4,6]]
    answer = [[0,1],[2,3,4,5]]
    assert solution.findCriticalAndPseudoCriticalEdges(n, edges) == answer
