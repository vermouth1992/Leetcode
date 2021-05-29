#
# @lc app=leetcode id=507 lang=python3
#
# [507] Perfect Number
#
# https://leetcode.com/problems/perfect-number/description/
#
# algorithms
# Easy (36.52%)
# Total Accepted:    81.9K
# Total Submissions: 224.1K
# Testcase Example:  '28'
#
# A perfect number is a positive integer that is equal to the sum of its
# positive divisors, excluding the number itself. A divisor of an integer x is
# an integer that can divide x evenly.
# 
# Given an integer n, return true if n is a perfect number, otherwise return
# false.
# 
# 
# Example 1:
# 
# 
# Input: num = 28
# Output: true
# Explanation: 28 = 1 + 2 + 4 + 7 + 14
# 1, 2, 4, 7, and 14 are all divisors of 28.
# 
# 
# Example 2:
# 
# 
# Input: num = 6
# Output: true
# 
# 
# Example 3:
# 
# 
# Input: num = 496
# Output: true
# 
# 
# Example 4:
# 
# 
# Input: num = 8128
# Output: true
# 
# 
# Example 5:
# 
# 
# Input: num = 2
# Output: false
# 
# 
# 
# Constraints:
# 
# 
# 1 <= num <= 10^8
# 
# 
#

class Solution:
    def checkPerfectNumber(self, num: int) -> bool:
        i = 1
        sum = 0
        while i * i < num:
            if num % i == 0:
                sum += i
                sum += num // i
            i += 1

        if i * i == num:
            sum += i

        sum -= num

        return sum == num


