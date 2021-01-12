class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        from collections import defaultdict

        dd = defaultdict(int)
        for i in s:
            dd[i] += 1
        for n, i in enumerate(s):
            if dd[i] == 1:
                return n
        return -1


def test_accuracy():
    s = "leetcode"
    sol = Solution()
    assert sol.firstUniqChar(s) == 0
    s = "loveleetcode"
    assert sol.firstUniqChar(s) == 2
