"""
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
"""

"""
For this particular problem, dp is not fastest. Direct math using Lagrange's four-square theorem is the fastest.
Another dp solution:
opt(i + 1) = min_k opt(i - k * k) + 1 or 1 if i + 1 is a number of k**2 
"""

class Solution(object):
    def numSquares(self, n):
        """
        :type n: int
        :rtype: int
        >>> Solution().numSquares(13)
        2
        >>> Solution().numSquares(12)
        3
        >>> Solution().numSquares(4)
        1
        >>> Solution().numSquares(8441)
        3
        """
        use_better_dp = False
        if use_better_dp:
            vec = [0 for i in range(0, n + 1)]
            next_k = 1
            for i in range(1, n + 1):
                if next_k * next_k == i:
                    vec[i] = 1
                    next_k += 1
                else:
                    result = n
                    for previous_k in range(1, next_k):
                        result = min(result, vec[i - previous_k * previous_k] + 1)
                    vec[i] = result
            return vec[n]
        else:
            import numpy as np
            vec_line_k = np.arange(n + 1)
            vec_line_k_plus_one = np.zeros(n + 1, dtype=int)
            k = 2
            while k * k <= n:
                for i in range(0, n + 1):
                    if i < k * k:
                        value = vec_line_k[i]
                    else:
                        value = min(vec_line_k[i], 1 + vec_line_k_plus_one[i - k * k])
                    vec_line_k_plus_one[i] = value
                k += 1
                vec_line_k = vec_line_k_plus_one
            return vec_line_k[n]


