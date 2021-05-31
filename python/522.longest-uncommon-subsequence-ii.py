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
    def isSubSequence(self, a: str, b: str):
        """ Return True if a is a subsequence of b
        """
        if len(b) < len(a):
            return False
        index_a = 0
        for i in range(len(b)):
            if b[i] == a[index_a]:
                index_a += 1
            if index_a == len(a):
                return True
        
        return False


    def findLUSlength(self, strs: List[str]) -> int:
        # sort the strings according to its length O(nlogn)
        strs = sorted(strs, reverse=True, key=len)
        flags = [False for _ in range(len(strs))]
        for i in range(len(strs)):
            success = True
            if not flags[i]:
                for j in range(len(strs)):
                    if i != j:
                        if self.isSubSequence(strs[i], strs[j]):
                            # find a string with the same length
                            if len(strs[i]) == len(strs[j]):
                                flags[j] = True
                            success = False
                            break
            else:
                success = False

            if success:
                return len(strs[i])
         
        return -1
            

if __name__ == '__main__':
    print(Solution().findLUSlength(["aba","cdc","eae"]))
    print(Solution().findLUSlength(["aaa","aaa","aa"]))
    print(Solution().findLUSlength(["aabbcc", "aabbcc","cb","abc"]))