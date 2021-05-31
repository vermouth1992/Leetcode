#
# @lc app=leetcode id=541 lang=python3
#
# [541] Reverse String II
#
# https://leetcode.com/problems/reverse-string-ii/description/
#
# algorithms
# Easy (49.66%)
# Total Accepted:    117.1K
# Total Submissions: 235.8K
# Testcase Example:  '"abcdefg"\n2'
#
# Given a string s and an integer k, reverse the first k characters for every
# 2k characters counting from the start of the string.
# 
# If there are fewer than k characters left, reverse all of them. If there are
# less than 2k but greater than or equal to k characters, then reverse the
# first k characters and left the other as original.
# 
# 
# Example 1:
# Input: s = "abcdefg", k = 2
# Output: "bacdfeg"
# Example 2:
# Input: s = "abcd", k = 2
# Output: "bacd"
# 
# 
# Constraints:
# 
# 
# 1 <= s.length <= 10^4
# s consists of only lowercase English letters.
# 1 <= k <= 10^4
# 
# 
#
class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        if len(s) < k:
            return self.reverseAllStr(s)
        elif len(s) >= k and len(s) < 2 * k:
            return self.reverseAllStr(s[:k]) + s[k:]
        else:
            return self.reverseAllStr(s[:k]) + s[k:2*k] + self.reverseStr(s[2*k:], k)

    def reverseAllStr(self, s: str):
        return s[::-1]

