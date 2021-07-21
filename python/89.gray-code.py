#
# @lc app=leetcode id=89 lang=python3
#
# [89] Gray Code
#
# https://leetcode.com/problems/gray-code/description/
#
# algorithms
# Medium (51.02%)
# Total Accepted:    197.5K
# Total Submissions: 376.1K
# Testcase Example:  '2'
#
# An n-bit gray code sequence is a sequence of 2^n integers where:
# 
# 
# Every integer is in the inclusive range [0, 2^n - 1],
# The first integer is 0,
# An integer appears no more than once in the sequence,
# The binary representation of every pair of adjacent integers differs by
# exactly one bit, and
# The binary representation of the first and last integers differs by exactly
# one bit.
# 
# 
# Given an integer n, return any valid n-bit gray code sequence.
# 
# 
# Example 1:
# 
# 
# Input: n = 2
# Output: [0,1,3,2]
# Explanation:
# The binary representation of [0,1,3,2] is [00,01,11,10].
# - 00 and 01 differ by one bit
# - 01 and 11 differ by one bit
# - 11 and 10 differ by one bit
# - 10 and 00 differ by one bit
# [0,2,3,1] is also a valid gray code sequence, whose binary representation is
# [00,10,11,01].
# - 00 and 10 differ by one bit
# - 10 and 11 differ by one bit
# - 11 and 01 differ by one bit
# - 01 and 00 differ by one bit
# 
# 
# Example 2:
# 
# 
# Input: n = 1
# Output: [0,1]
# 
# 
# 
# Constraints:
# 
# 
# 1 <= n <= 16
# 
# 
#

from typing import List

class Solution:
    def grayCode(self, n: int) -> List[int]:
        visited = [False] * (2 ** n)
        current = [0]
        visited[0] = True
        result = self.helper(current, visited, n)
        assert result
        return current

    def helper(self, current: List[int], visited: List[bool], n: int) -> bool:
        if len(current) == len(visited):
            return True
        prev = current[-1]
        # find all the possible next element of prev
        possible_next = self.getNext(prev, n)
        for next in possible_next:
            if not visited[next]:
                current.append(next)
                visited[next] = True
                result = self.helper(current, visited, n)
                if result:
                    return True
                current.pop()
                visited[next] = False
        
        return False

        
    def getNext(self, prev: int, n: int) -> List[int]:
        binary = bin(prev)[2:].zfill(n)
        output = []
        for i, char in enumerate(binary):
            if char == '0':
                output.append(prev + 2 ** (n - 1 - i))
            else:
                output.append(prev - 2 ** (n - 1 - i))
        return output
