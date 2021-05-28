#
# @lc app=leetcode id=504 lang=python3
#
# [504] Base 7
#
# https://leetcode.com/problems/base-7/description/
#
# algorithms
# Easy (46.55%)
# Total Accepted:    67.6K
# Total Submissions: 145.2K
# Testcase Example:  '100'
#
# Given an integer num, return a string of its base 7 representation.
# 
# 
# Example 1:
# Input: num = 100
# Output: "202"
# Example 2:
# Input: num = -7
# Output: "-10"
# 
# 
# Constraints:
# 
# 
# -10^7 <= num <= 10^7
# 
# 
#
class Solution:
    def convertToBase7(self, num: int) -> str:
        if num == 0:
            return '0'
        elif num < 0:
            return '-' + self.convertToBase7(-num)
        else:
            result = ''
            while num >= 7:
                q, mod = divmod(num, 7)
                result = str(mod) + result
                num = q
            result = str(num) + result
            return result

if __name__ == '__main__':
    import sys
    print(Solution().convertToBase7(int(sys.argv[1])))

