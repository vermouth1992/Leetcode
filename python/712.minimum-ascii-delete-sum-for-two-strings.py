#
# @lc app=leetcode id=712 lang=python3
#
# [712] Minimum ASCII Delete Sum for Two Strings
#
# https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/
#
# algorithms
# Medium (59.81%)
# Total Accepted:    48.5K
# Total Submissions: 81K
# Testcase Example:  '"sea"\n"eat"'
#
# Given two strings s1 and s2, return the lowest ASCII sum of deleted
# characters to make two strings equal.
# 
# 
# Example 1:
# 
# 
# Input: s1 = "sea", s2 = "eat"
# Output: 231
# Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the
# sum.
# Deleting "t" from "eat" adds 116 to the sum.
# At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum
# possible to achieve this.
# 
# 
# Example 2:
# 
# 
# Input: s1 = "delete", s2 = "leet"
# Output: 403
# Explanation: Deleting "dee" from "delete" to turn the string into "let",
# adds 100[d] + 101[e] + 101[e] to the sum.
# Deleting "e" from "leet" adds 101[e] to the sum.
# At the end, both strings are equal to "let", and the answer is
# 100+101+101+101 = 403.
# If instead we turned both strings into "lee" or "eet", we would get answers
# of 433 or 417, which are higher.
# 
# 
# 
# Constraints:
# 
# 
# 1 <= s1.length, s2.length <= 1000
# s1 and s2 consist of lowercase English letters.
# 
# 
#
class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        opt = []
        for i in range(len(s1) + 1):
            opt.append([])
            for j in range(len(s2) + 1):
                opt[i].append(0)

        for i in range(len(s1)):
            opt[i + 1][0] = opt[i][0] + ord(s1[i])

        for i in range(len(s2)):
            opt[0][i + 1] = opt[0][i] + ord(s2[i])

        for i in range(1, len(s1) + 1):
            for j in range(1, len(s2) + 1):
                if s1[i - 1] == s2[j - 1]:
                    opt[i][j] = opt[i - 1][j - 1]
                else:
                    opt[i][j] = min(opt[i - 1][j] + ord(s1[i - 1]), opt[i][j - 1] + ord(s2[j - 1]))

        return opt[len(s1)][len(s2)]
