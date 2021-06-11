#
# @lc app=leetcode id=583 lang=python3
#
# [583] Delete Operation for Two Strings
#
# https://leetcode.com/problems/delete-operation-for-two-strings/description/
#
# algorithms
# Medium (51.92%)
# Total Accepted:    83.6K
# Total Submissions: 160.8K
# Testcase Example:  '"sea"\n"eat"'
#
# Given two strings word1 and word2, return the minimum number of steps
# required to make word1 and word2 the same.
# 
# In one step, you can delete exactly one character in either string.
# 
# 
# Example 1:
# 
# 
# Input: word1 = "sea", word2 = "eat"
# Output: 2
# Explanation: You need one step to make "sea" to "ea" and another step to make
# "eat" to "ea".
# 
# 
# Example 2:
# 
# 
# Input: word1 = "leetcode", word2 = "etco"
# Output: 4
# 
# 
# 
# Constraints:
# 
# 
# 1 <= word1.length, word2.length <= 500
# word1 and word2 consist of only lowercase English letters.
# 
# 
#


class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        opt = []
        for i in range(len(word1) + 1):
            opt.append([])
            for j in range(len(word2) + 1):
                opt[i].append(0)

        for i in range(len(word1) + 1):
            opt[i][0] = i

        for i in range(len(word2) + 1):
            opt[0][i] = i

        for i in range(1, len(word1) + 1):
            for j in range(1, len(word2) + 1):
                if word1[i - 1] == word2[j - 1]:
                    opt[i][j] = opt[i - 1][j - 1]
                else:
                    opt[i][j] = min(opt[i - 1][j], opt[i][j - 1]) + 1

        return opt[len(word1)][len(word2)]


if __name__ == '__main__':
    print(Solution().minDistance('leetcode', 'etco'))
