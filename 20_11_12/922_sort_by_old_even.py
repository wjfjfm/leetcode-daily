class Solution(object):
    def sortArrayByParityII(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        olds = []
        evens = []
        for i in A:
            if i % 2 == 0:
                evens.append(i)
            else:
                olds.append(i)
        
        results = []
        for i in range(len(olds)):
            results.append(evens[i])
            results.append(olds[i])

        return results