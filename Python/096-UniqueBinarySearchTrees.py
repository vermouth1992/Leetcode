"""
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
"""


class Solution(object):
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        >>> Solution().numTrees(1)
        1
        >>> Solution().numTrees(2)
        2
        >>> Solution().numTrees(3)
        5
        >>> Solution().numTrees(4)
        14
        """
        if n <= 1:
            return 1
        vec = [1, 1]
        for i in range(2, n + 1):
            total = 0
            if i % 2 == 0:
                for j in range(i // 2):
                    total += vec[j] * vec[i - j - 1]
                total *= 2
            else:
                for j in range((i - 1) // 2):
                    total += vec[j] * vec[i - j - 1]
                total = total * 2 + vec[(i - 1) // 2] ** 2
            vec.append(total)
        return vec[n]
