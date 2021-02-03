from typing import List

class Solution:
    def medianSlidingWindow(self, nums: List[int], k: int) -> List[float]:
        def medNum(window):
            len_window = len(window)
            if len_window % 2 == 0:
                mednum = (window[int(len_window/2)] + window[intclass Solution:
    def medianSlidingWindow(self, nums: List[int], k: int) -> List[float]:
        def medNum(window):
            len_window = len(window)
            if len_window % 2 == 0:
                mednum = (window[int(len_window/2)] + window[int(len_window/2)-1]) / 2
            else:
                mednum = window[int((len_window-1)/2)]
            return mednum

        window = nums[0:k]
        window.sort()
        answer = []
        answer.append(medNum(window))

        # print(window)
        # print(answer)

        for i in range(k, len(nums)):
            window.append(nums[i])
            window.remove(nums[i-k])
            window.sort()
            answer.append(medNum(window))
            # print(window)
            # print(answer)

        return answer
(len_window/2)-1]) / 2
            else:
                mednum = window[int((len_window-1)/2)]
            return mednum

        window = nums[0:k]
        window.sort()
        answer = []
        answer.append(medNum(window))

        # print(window)
        # print(answer)

        for i in range(k, len(nums)):
            window.append(nums[i])
            window.remove(nums[i-k])
            window.sort()
            answer.append(medNum(window))
            # print(window)
            # print(answer)

        return answer


def test_leetcode480():
    solution = Solution()
    nums = [1,3,-1,-3,5,3,6,7]
    k = 3
    answer = [1, -1, -1, 3, 5, 6]
    assert solution.medianSlidingWindow(nums, k) == answer


if __name__ == '__main__':
    test_leetcode480()
