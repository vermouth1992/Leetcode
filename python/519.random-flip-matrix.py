#
# @lc app=leetcode id=519 lang=python3
#
# [519] Random Flip Matrix
#
# https://leetcode.com/problems/random-flip-matrix/description/
#
# algorithms
# Medium (37.96%)
# Total Accepted:    10.6K
# Total Submissions: 27.9K
# Testcase Example:  '["Solution", "flip", "flip", "flip", "flip"]\n[[2, 2], [], [], [], []]'
#
# You are given the number of rows n_rows and number of columns n_cols of a 2D
# binary matrix where all values are initially 0. Write a function flip which
# chooses a 0 value uniformly at random, changes it to 1, and then returns the
# position [row.id, col.id] of that value. Also, write a function reset which
# sets all values back to 0. Try to minimize the number of calls to system's
# Math.random() and optimize the time and space complexity.
# 
# Note:
# 
# 
# 1 <= n_rows, n_cols <= 10000
# 0 <= row.id < n_rows and 0 <= col.id < n_cols
# flip will not be called when the matrix has no 0 values left.
# the total number of calls to flip and reset will not exceed 1000.
# 
# 
# Example 1:
# 
# 
# Input: 
# ["Solution","flip","flip","flip","flip"]
# [[2,3],[],[],[],[]]
# Output: [null,[0,1],[1,2],[1,0],[1,1]]
# 
# 
# 
# Example 2:
# 
# 
# Input: 
# ["Solution","flip","flip","reset","flip"]
# [[1,2],[],[],[],[]]
# Output: [null,[0,0],[0,1],null,[0,0]]
# 
# 
# Explanation of Input Syntax:
# 
# The input is two lists: the subroutines called and their arguments.
# Solution's constructor has two arguments, n_rows and n_cols. flip and reset
# have no arguments. Arguments are always wrapped with a list, even if there
# aren't any.
# 
#

import random
from typing import List

class Solution:

    def __init__(self, n_rows: int, n_cols: int):
        self.used = set()
        self.n_rows = n_rows
        self.n_cols = n_cols
        self.max_int = self.n_rows * self.n_cols

    def _idx_to_pos(self, idx):
        col = idx // self.n_rows
        row = idx - col * self.n_rows
        return [row, col]

    def flip(self) -> List[int]:
        idx = random.randint(0, self.max_int - 1)
        while idx in self.used:
            idx += 1
            if idx == self.max_int:
                idx = 0
        self.used.add(idx)
        return self._idx_to_pos(idx)

    def reset(self) -> None:
        self.used = set()
        


# Your Solution object will be instantiated and called as such:
# obj = Solution(n_rows, n_cols)
# param_1 = obj.flip()
# obj.reset()
