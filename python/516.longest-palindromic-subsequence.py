#
# @lc app=leetcode id=516 lang=python3
#
# [516] Longest Palindromic Subsequence
#
# https://leetcode.com/problems/longest-palindromic-subsequence/description/
#
# algorithms
# Medium (56.28%)
# Total Accepted:    173.4K
# Total Submissions: 308.1K
# Testcase Example:  '"bbbab"'
#
# Given a string s, find the longest palindromic subsequence's length in s.
# 
# A subsequence is a sequence that can be derived from another sequence by
# deleting some or no elements without changing the order of the remaining
# elements.
# 
# 
# Example 1:
# 
# 
# Input: s = "bbbab"
# Output: 4
# Explanation: One possible longest palindromic subsequence is "bbbb".
# 
# 
# Example 2:
# 
# 
# Input: s = "cbbd"
# Output: 2
# Explanation: One possible longest palindromic subsequence is "bb".
# 
# 
# 
# Constraints:
# 
# 
# 1 <= s.length <= 1000
# s consists only of lowercase English letters.
# 
# 
#

class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        # initialize table
        table = [[0 for _ in range(len(s))] for _ in range(len(s))]
        for i in range(len(s)):
            table[i][i] = 1

        for diff in range(1, len(s)):
            for i in range(0, len(s) - diff):
                j = i + diff
                if s[i] == s[j]:
                    table[i][j] = max(table[i + 1][j - 1] + 2, table[i + 1][j], table[i][j - 1])
                else:
                    table[i][j] = max(table[i + 1][j], table[i][j - 1])
        print(table)
        return table[0][len(s) - 1]


if __name__ == '__main__':
    import sys
    s = sys.argv[1]
    print(Solution().longestPalindromeSubseq(s))