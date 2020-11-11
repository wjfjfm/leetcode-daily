class Solution(object):
    def findRotateSteps(self, ring, key):
        """
        :type ring: str
        :type key: str
        :rtype: int
        """

        def distance(a, b):
            return min(abs(a-b), abs(len(ring)-abs(a-b)))+1
        
        index_dict = {}
        for n, i in enumerate(ring):
            if i in index_dict:
                index_dict[i].append(n)
            else:
                index_dict[i] = [n]
        
        MAX = 1e9
        dp = {0: 0}
        for key_i in key:
            dp_next = {}
            for key_n in index_dict[key_i]:
                dp_next[key_n] = MAX
                for loc, step in dp.items():
                    dp_next[key_n] = min(dp_next[key_n], distance(loc, key_n)+step)

            dp = dp_next
                
        return min(dp.values())


if __name__ == '__main__':
    solution = Solution()
    print(solution.findRotateSteps("godding", "gd"))