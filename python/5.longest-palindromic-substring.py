#
# @lc app=leetcode id=5 lang=python3
#
# [5] Longest Palindromic Substring
#
# https://leetcode.com/problems/longest-palindromic-substring/description/
#
# algorithms
# Medium (30.82%)
# Total Accepted:    1.3M
# Total Submissions: 4.4M
# Testcase Example:  '"babad"'
#
# Given a string s, return the longest palindromic substring in s.
# 
# 
# Example 1:
# 
# 
# Input: s = "babad"
# Output: "bab"
# Note: "aba" is also a valid answer.
# 
# 
# Example 2:
# 
# 
# Input: s = "cbbd"
# Output: "bb"
# 
# 
# Example 3:
# 
# 
# Input: s = "a"
# Output: "a"
# 
# 
# Example 4:
# 
# 
# Input: s = "ac"
# Output: "a"
# 
# 
# 
# Constraints:
# 
# 
# 1 <= s.length <= 1000
# s consist of only digits and English letters (lower-case and/or upper-case),
# 
# 
#

class Solution:
    def longestPalindrome(self, s: str) -> str:
        table = [[True for _ in range(len(s))] for _ in range(len(s))]
        max_length = 1
        max_length_index = [0, 1]

        for j in range(1, len(s)):
            for i in range(len(s) - j):
                if s[i] == s[i + j]:
                    table[i][i + j] = table[i + 1][i + j - 1]
                    if table[i][i + j]:
                        if j + 1 > max_length:
                            max_length = j + 1
                            max_length_index = [i, i + j + 1]
                else:
                    table[i][i + j] = False

        return s[max_length_index[0]:max_length_index[1]]


if __name__ == '__main__':
    print(Solution().longestPalindrome("aacabdkacaa"))