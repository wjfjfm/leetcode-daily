from typing import List
class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        def union(ufs, a, b):
            if find(ufs, a) != find(ufs, b):
                ufs[find(ufs, a)] = find(ufs, b)

        def find(ufs, a):
            if ufs.get(a) is not None:
                ufs[a] = find(ufs, ufs[a])
                return ufs[a]
            else:
                return a

        ufs = {}
        name_dict = {}
        for account in accounts:
            name = account[0]
            first_mail = account[1]
            name_dict[first_mail] = name
            for mail in account[2:]:
                name_dict[mail] = name
                union(ufs, mail, first_mail)

        result_dict = {}
        for mail in sorted(name_dict.keys()):
            name = name_dict[mail]
            clas = find(ufs, mail)
            if result_dict.get(clas) is None:
                result_dict[clas] = [name]
            result_dict[clas].append(mail)
        return list(result_dict.values())


def test_leetcode_721():
    solution = Solution()
    accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John", "johnnybravo@mail.com"], ["John", "johnsmith@mail.com", "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]
    answer = [["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],  ["John", "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]]
    result = solution.accountsMerge(accounts)
    assert solution.accountsMerge(accounts) == answer


if __name__ == '__main__':
    test_leetcode_721()

