#
# @lc app=leetcode id=695 lang=python3
#
# [695] Max Area of Island
#
# https://leetcode.com/problems/max-area-of-island/description/
#
# algorithms
# Medium (65.75%)
# Total Accepted:    287.2K
# Total Submissions: 430.8K
# Testcase Example:  '[[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]'
#
# You are given an m x n binary matrix grid. An island is a group of 1's
# (representing land) connected 4-directionally (horizontal or vertical.) You
# may assume all four edges of the grid are surrounded by water.
# 
# The area of an island is the number of cells with a value 1 in the island.
# 
# Return the maximum area of an island in grid. If there is no island, return
# 0.
# 
# 
# Example 1:
# 
# 
# Input: grid =
# [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
# Output: 6
# Explanation: The answer is not 11, because the island must be connected
# 4-directionally.
# 
# 
# Example 2:
# 
# 
# Input: grid = [[0,0,0,0,0,0,0,0]]
# Output: 0
# 
# 
# 
# Constraints:
# 
# 
# m == grid.length
# n == grid[i].length
# 1 <= m, n <= 50
# grid[i][j] is either 0 or 1.
# 
# 
#

from typing import List

class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        explored_ones = set()
        max_area = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1 and (i, j) not in explored_ones:
                    # start explore the current island
                    current_area = self.exploreIsland(grid, (i, j), explored_ones)
                    if current_area > max_area:
                        max_area = current_area

        return max_area

    def exploreIsland(self, grid, position, explored_ones: set):
        area = 0
        current_explored = set()
        queue = [position]
        while len(queue) > 0:
            pos = queue.pop()
            if pos not in current_explored:
                current_explored.add(pos)
                explored_ones.add(pos)
                i, j = pos
                possible_pos = [(i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)]
                area += 1

                for x, y in possible_pos:
                    if x >= 0 and x < len(grid) and y >= 0 and y < len(grid[0]):
                        if grid[x][y] == 1:
                            if (x, y) not in current_explored:
                                queue.append((x, y))
        
        return area

