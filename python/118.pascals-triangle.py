#
# @lc app=leetcode id=118 lang=python3
#
# [118] Pascal's Triangle
#
# https://leetcode.com/problems/pascals-triangle/description/
#
# algorithms
# Easy (56.20%)
# Total Accepted:    522.6K
# Total Submissions: 912.8K
# Testcase Example:  '5'
#
# Given an integer numRows, return the first numRows of Pascal's triangle.
# 
# In Pascal's triangle, each number is the sum of the two numbers directly
# above it as shown:
# 
# 
# Example 1:
# Input: numRows = 5
# Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
# Example 2:
# Input: numRows = 1
# Output: [[1]]
# 
# 
# Constraints:
# 
# 
# 1 <= numRows <= 30
# 
# 
#

from typing import List

class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        output = [[1]]
        for i in range(1, numRows):
            output.append([1])
            for j in range(i - 1):
                output[i].append(output[i - 1][j] + output[i - 1][j + 1])
            output[i].append(1)
        return output

if __name__ == '__main__':
    print(Solution().generate(5))