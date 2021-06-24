#
# @lc app=leetcode id=576 lang=python3
#
# [576] Out of Boundary Paths
#
# https://leetcode.com/problems/out-of-boundary-paths/description/
#
# algorithms
# Medium (36.32%)
# Total Accepted:    37.6K
# Total Submissions: 103.6K
# Testcase Example:  '2\n2\n2\n0\n0'
#
# There is an m x n grid with a ball. The ball is initially at the position
# [startRow, startColumn]. You are allowed to move the ball to one of the four
# adjacent four cells in the grid (possibly out of the grid crossing the grid
# boundary). You can apply at most maxMove moves to the ball.
# 
# Given the five integers m, n, maxMove, startRow, startColumn, return the
# number of paths to move the ball out of the grid boundary. Since the answer
# can be very large, return it modulo 10^9 + 7.
# 
# 
# Example 1:
# 
# 
# Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
# Output: 6
# 
# 
# Example 2:
# 
# 
# Input: m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
# Output: 12
# 
# 
# 
# Constraints:
# 
# 
# 1 <= m, n <= 50
# 0 <= maxMove <= 50
# 0 <= startRow <= m
# 0 <= startColumn <= n
# 
# 
#

class Solution:
    def findPaths(self, m: int, n: int, maxMove: int, startRow: int, startColumn: int) -> int:
        if maxMove == 0:
            return 0

        table = []
        for move in range(maxMove):
            table.append([])
            for row in range(m):
                table[move].append([])
                for col in range(n):
                    table[move][row].append(0)

        # all the boundaries are 1
        for row in range(m):
            table[0][row][0] += 1
            table[0][row][n - 1] += 1
        for col in range(n):
            table[0][0][col] += 1
            table[0][m - 1][col] += 1

        for move in range(1, maxMove):
            for row in range(m):
                for col in range(n):
                    if row > 0:
                        table[move][row][col] += table[move - 1][row - 1][col]
                    if row < m - 1:
                        table[move][row][col] += table[move - 1][row + 1][col]
                    if col > 0:
                        table[move][row][col] += table[move - 1][row][col - 1]
                    if col < n - 1:
                        table[move][row][col] += table[move - 1][row][col + 1]

        result = 0
        for move in range(maxMove):
            result += table[move][startRow][startColumn]

        return result % 1000000007
                

if __name__ == '__main__':
    print(Solution().findPaths(1, 3, 3, 0, 1))