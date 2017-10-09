"""
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
"""

"""
dp: opt(n) = max{opt(n - 1) + f(n), f(n)}
"""

class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        >>> Solution().maxSubArray([-2,1,-3,4,-1,2,1,-5,4])
        6
        """
        use_dp = True
        if len(nums) == 0:
            return 0
        maxSum = nums[0]
        currentMax = nums[0]
        if use_dp:
            for i in range(1, len(nums)):
                if currentMax > 0:
                    currentMax += nums[i]
                else:
                    currentMax = nums[i]
                maxSum = max(currentMax, maxSum)
            return maxSum
        else:
            pass
