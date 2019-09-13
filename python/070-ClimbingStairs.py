"""
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.
"""

class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        >>> Solution().climbStairs(1)
        1
        >>> Solution().climbStairs(2)
        2
        >>> Solution().climbStairs(3)
        3
        """
        vec = [0 for i in range(n + 1)]
        vec[0] = 1
        vec[1] = 1
        for i in range(2, n + 1):
            vec[i] = vec[i - 1] + vec[i - 2]
        return vec[n]
