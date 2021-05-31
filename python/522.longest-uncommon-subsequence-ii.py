#
# @lc app=leetcode id=522 lang=python3
#
# [522] Longest Uncommon Subsequence II
#
# https://leetcode.com/problems/longest-uncommon-subsequence-ii/description/
#
# algorithms
# Medium (34.28%)
# Total Accepted:    25K
# Total Submissions: 73K
# Testcase Example:  '["aba","cdc","eae"]'
#
# Given an array of strings strs, return the length of the longest uncommon
# subsequence between them. If the longest uncommon subsequence does not exist,
# return -1.
# 
# An uncommon subsequence between an array of strings is a string that is a
# subsequence of one string but not the others.
# 
# A subsequence of a string s is a string that can be obtained after deleting
# any number of characters from s.
# 
# 
# For example, "abc" is a subsequence of "aebdc" because you can delete the
# underlined characters in "aebdc" to get "abc". Other subsequences of "aebdc"
# include "aebdc", "aeb", and "" (empty string).
# 
# 
# 
# Example 1:
# Input: strs = ["aba","cdc","eae"]
# Output: 3
# Example 2:
# Input: strs = ["aaa","aaa","aa"]
# Output: -1
# 
# 
# Constraints:
# 
# 
# 1 <= strs.length <= 50
# 1 <= strs[i].length <= 10
# strs[i] consists of lowercase English letters.
# 
# 
#

from typing import List

class Solution:
    def findLUSlengthHelper(self, a: str, b: str) -> int:
        if len(a) != len(b):
            return max(len(a), len(b))
        else:
            for i in range(len(a)):
                if a[i] != b[i]:
                    return len(a)
            return -1
    
    def findLUSlength(self, strs: List[str]) -> int:
        results = [[0 for _ in range(len(strs))] for _ in range(len(str))]
        for i in range(len(strs)):
            for j in range(i + 1, len(strs)):
                out = self.findLUSlengthHelper(strs[i], strs[j])
                results[i][j] = out
                results[j][i] = out
        
        curr_max_length = -1
        for i in range(len(strs)):
            for j in range(len(strs)):
                pass