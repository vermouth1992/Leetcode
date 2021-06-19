#
# @lc app=leetcode id=709 lang=python3
#
# [709] To Lower Case
#
# https://leetcode.com/problems/to-lower-case/description/
#
# algorithms
# Easy (80.60%)
# Total Accepted:    292.3K
# Total Submissions: 362.5K
# Testcase Example:  '"Hello"'
#
# Given a string s, return the string after replacing every uppercase letter
# with the same lowercase letter.
# 
# 
# Example 1:
# 
# 
# Input: s = "Hello"
# Output: "hello"
# 
# 
# Example 2:
# 
# 
# Input: s = "here"
# Output: "here"
# 
# 
# Example 3:
# 
# 
# Input: s = "LOVELY"
# Output: "lovely"
# 
# 
# 
# Constraints:
# 
# 
# 1 <= s.length <= 100
# s consists of printable ASCII characters.
# 
# 
#
class Solution:
    def toLowerCase(self, s: str) -> str:
        output = ''
        for char in s:
            dec = ord(char)
            if dec >= 65 and dec <= 90:
                output += chr(dec + 32)
            else:
                output += char
        return output
