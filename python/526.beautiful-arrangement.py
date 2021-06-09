#
# @lc app=leetcode id=526 lang=python3
#
# [526] Beautiful Arrangement
#
# https://leetcode.com/problems/beautiful-arrangement/description/
#
# algorithms
# Medium (62.30%)
# Total Accepted:    93.6K
# Total Submissions: 150.2K
# Testcase Example:  '2'
#
# Suppose you have n integers labeled 1 through n. A permutation of those n
# integers perm (1-indexed) is considered a beautiful arrangement if for every
# i (1 <= i <= n), either of the following is true:
# 
# 
# perm[i] is divisible by i.
# i is divisible by perm[i].
# 
# 
# Given an integer n, return the number of the beautiful arrangements that you
# can construct.
# 
# 
# Example 1:
# 
# 
# Input: n = 2
# Output: 2
# Explanation: 
# The first beautiful arrangement is [1,2]:
# ⁠   - perm[1] = 1 is divisible by i = 1
# ⁠   - perm[2] = 2 is divisible by i = 2
# The second beautiful arrangement is [2,1]:
# ⁠   - perm[1] = 2 is divisible by i = 1
# ⁠   - i = 2 is divisible by perm[2] = 1
# 
# 
# Example 2:
# 
# 
# Input: n = 1
# Output: 1
# 
# 
# 
# Constraints:
# 
# 
# 1 <= n <= 15
# 
# 
#

from typing import Set

class Solution:
    def countArrangement(self, n: int) -> int:
        available_nums = set([i + 1 for i in range(n)])
        return self.countArrangementHelper(1, n, available_nums)
    
    def countArrangementHelper(self, start_index: int, end_index: int, available_nums: Set[int]) -> int:
        # base case
        if start_index == end_index:
            element = list(available_nums)[0]
            if element % start_index == 0 or start_index % element == 0:
                return 1
            else:
                return 0

        total = 0
        for num in available_nums:
            if num % start_index == 0 or start_index % num == 0:
                available_nums_copy = available_nums.copy()
                available_nums_copy.remove(num)
                count = self.countArrangementHelper(start_index + 1, end_index, available_nums_copy)
                total += count
        return total

