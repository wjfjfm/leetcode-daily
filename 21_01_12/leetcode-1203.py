from typing import List


class Solution:
    def get_position(self, i, item_dict, group_dict, topo, group):
        if i not in item_dict.keys():
            if group[i] == -1:
                topo.append([i, 0, []])
                item_dict[i] = [(len(topo) - 1)]
            else:
                if group[i] not in group_dict.keys():
                    topo.append([[], 0, []])
                    group_dict[group[i]] = len(topo) - 1
                topo_index = group_dict[group[i]]
                topo[topo_index][0].append([i, 0, []])
                item_dict[i] = [topo_index, len(topo[topo_index][0]) - 1]
        return item_dict[i]

    def generate_topo(self, n, m, group, beforeItems):

        item_dict = {}
        group_dict = {}
        topo = []
        for i in range(n):
            self.get_position(i, item_dict, group_dict, topo, group)
        for i in range(n):
            for bi in beforeItems[i]:
                if group[i] == group[bi] and group[i] != -1:
                    topo[item_dict[i][0]][0][item_dict[i][1]][1] += 1
                    topo[item_dict[bi][0]][0][item_dict[bi][1]][2].append(item_dict[i][1])
                else:
                    pos_i = item_dict[i][0]
                    pos_bi = item_dict[bi][0]
                    if pos_i not in topo[pos_bi][2]:
                        topo[pos_bi][2].append(pos_i)
                        topo[pos_i][1] += 1
        return topo

    def topo_rank(self, topo):
        result = []
        flag = True
        while flag is True:
            flag = False
            for i in topo:
                if i[1] == 0:
                    flag = True
                    if isinstance(i[0], int):
                        result.append(i[0])
                    else:
                        result = result + self.topo_rank(i[0])

                    for ai in i[2]:
                        topo[ai][1] -= 1
                    i[1] = -1
        return result

    def sortItems(self, n: int, m: int, group: List[int], beforeItems: List[List[int]]) -> List[int]:
        topo = self.generate_topo(n, m, group, beforeItems)
        result = self.topo_rank(topo)
        if len(result) == n:
            return result
        else:
            return []


def test_leetcode_1202():
    solution = Solution()
    n = 8
    m = 2
    group = [-1, -1, 1, 0, 0, 1, 0, -1]
    beforeItems = [[], [6], [5], [6], [3], [], [4], []]
    answer = []
    assert solution.sortItems(n, m, group, beforeItems) == answer


if __name__ == '__main__':
    test_leetcode_1202()
