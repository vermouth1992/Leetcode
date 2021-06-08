#
# @lc app=leetcode id=680 lang=python3
#
# [680] Valid Palindrome II
#
# https://leetcode.com/problems/valid-palindrome-ii/description/
#
# algorithms
# Easy (37.22%)
# Total Accepted:    275.1K
# Total Submissions: 737.9K
# Testcase Example:  '"aba"'
#
# Given a string s, return true if the s can be palindrome after deleting at
# most one character from it.
# 
# 
# Example 1:
# 
# 
# Input: s = "aba"
# Output: true
# 
# 
# Example 2:
# 
# 
# Input: s = "abca"
# Output: true
# Explanation: You could delete the character 'c'.
# 
# 
# Example 3:
# 
# 
# Input: s = "abc"
# Output: false
# 
# 
# 
# Constraints:
# 
# 
# 1 <= s.length <= 10^5
# s consists of lowercase English letters.
# 
# 
#
class Solution:
    def validPalindrome(self, s: str) -> bool:
        head = 0
        tail = len(s) - 1
        while head < tail:
            if s[head] == s[tail]:
                head += 1
                tail -= 1
            else:
                return self.isPalindrome(s[head+1:tail+1]) or self.isPalindrome(s[head:tail])
        return True
    
    def isPalindrome(self, s: str) -> bool:
        head = 0
        tail = len(s) - 1
        while head < tail:
            if s[head] == s[tail]:
                head += 1
                tail -= 1
            else:
                return False
        return True
