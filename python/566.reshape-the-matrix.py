#
# @lc app=leetcode id=566 lang=python3
#
# [566] Reshape the Matrix
#
# https://leetcode.com/problems/reshape-the-matrix/description/
#
# algorithms
# Easy (61.09%)
# Total Accepted:    118K
# Total Submissions: 193.1K
# Testcase Example:  '[[1,2],[3,4]]\n1\n4'
#
# In MATLAB, there is a handy function called reshape which can reshape an m x
# n matrix into a new one with a different size r x c keeping its original
# data.
# 
# You are given an m x n matrix mat and two integers r and c representing the
# row number and column number of the wanted reshaped matrix.
# 
# The reshaped matrix should be filled with all the elements of the original
# matrix in the same row-traversing order as they were.
# 
# If the reshape operation with given parameters is possible and legal, output
# the new reshaped matrix; Otherwise, output the original matrix.
# 
# 
# Example 1:
# 
# 
# Input: mat = [[1,2],[3,4]], r = 1, c = 4
# Output: [[1,2,3,4]]
# 
# 
# Example 2:
# 
# 
# Input: mat = [[1,2],[3,4]], r = 2, c = 4
# Output: [[1,2],[3,4]]
# 
# 
# 
# Constraints:
# 
# 
# m == mat.length
# n == mat[i].length
# 1 <= m, n <= 100
# -1000 <= mat[i][j] <= 1000
# 1 <= r, c <= 300
# 
# 
#

from typing import List

class Solution:
    def matrixReshape(self, mat: List[List[int]], r: int, c: int) -> List[List[int]]:
        row = len(mat)
        if row == 0:
            return mat
        col = len(mat[0])
        if r * c != row * col:
            return mat

        output = []
        idx = 0
        for i in range(r):
            output.append([])
            for _ in range(c):
                output[i].append(mat[idx // col][idx % col])
                idx += 1

        return output


if __name__ == '__main__':
    print(Solution().matrixReshape([[1, 2, 3, 4]], 2, 2))