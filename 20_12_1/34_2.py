class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        if len(nums) == 0:
            return [-1, -1]

        l1 = l2 = 0
        r1 = r2 = len(nums)-1

        while(l1<r1):
            if(l1 + 1 == r1):
                if (l1 != target and r1 == target):
                    left = r1
                    break
            if(l1 == r1):
                if nums[l1] == target:
                    left = l1
                    break
                else:
                    return [-1, -1]
                
            mid = int( (l1 + r1) / 2)
            if(nums[mid]>=target):
                r1 = mid
            elif(nums[mid]<target):
                l1 = mid

        l2 = left
        while(l2<r2):
            if(l2 + 1 == r2):
                if (r2 != target and l2 == target):
                    right = l2
                    return [left, right]

            if l2 == r2:
                if nums[l2] == target:
                    right = l2
                    return [left, right]
            mid = int( (l2 + r2 -1) / 2)
            if(nums[mid] <= target):
                l2 = mid
            else:
                r2 = mid

        
