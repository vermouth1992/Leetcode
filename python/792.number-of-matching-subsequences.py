#
# @lc app=leetcode id=792 lang=python3
#
# [792] Number of Matching Subsequences
#
# https://leetcode.com/problems/number-of-matching-subsequences/description/
#
# algorithms
# Medium (48.58%)
# Total Accepted:    79.4K
# Total Submissions: 163K
# Testcase Example:  '"abcde"\n["a","bb","acd","ace"]'
#
# Given a string s and an array of strings words, return the number of words[i]
# that is a subsequence of s.
# 
# A subsequence of a string is a new string generated from the original string
# with some characters (can be none) deleted without changing the relative
# order of the remaining characters.
# 
# 
# For example, "ace" is a subsequence of "abcde".
# 
# 
# 
# Example 1:
# 
# 
# Input: s = "abcde", words = ["a","bb","acd","ace"]
# Output: 3
# Explanation: There are three strings in words that are a subsequence of s:
# "a", "acd", "ace".
# 
# 
# Example 2:
# 
# 
# Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
# Output: 2
# 
# 
# 
# Constraints:
# 
# 
# 1 <= s.length <= 5 * 10^4
# 1 <= words.length <= 5000
# 1 <= words[i].length <= 50
# s and words[i] consist of only lowercase English letters.
# 
# 
#

from typing import Dict, List

"""
A very clever idea: store the list of index of the char.
Check if a substring: for each char in w_i, w_{i+1}, find a sequence of index, such that the latter one must be
greater than the previous one. The search can be performed in O(log N).
"""


class Solution:
    def numMatchingSubseq(self, s: str, words: List[str]) -> int:
        char_to_index_lst = dict()
        for i, char in enumerate(s):
            if char not in char_to_index_lst:
                char_to_index_lst[char] = []
            char_to_index_lst[char].append(i)

        total = 0
        valid_set = set()
        for word in words:
            if word in valid_set:
                total += 1
            elif self.isSubsequence(word, char_to_index_lst):
                total += 1
                valid_set.add(word)
        return total

    def findLargerElement(self, index_lst: List[int], index: int) -> int:
        if index_lst[-1] <= index:
            return -1
        # binary search
        return self.binarySearch(index_lst, index, 0, len(index_lst) - 1)

    def binarySearch(self, index_lst: List[int], index: int, start, end) -> int:
        if end == start:
            return index_lst[start]

        mid = (start + end) // 2

        if index < index_lst[mid]:
            return self.binarySearch(index_lst, index, start, mid)
        else:
            return self.binarySearch(index_lst, index, mid + 1, end)


    def isSubsequence(self, word: str, char_to_index_lst: Dict[str, List[int]]):
        prev_index = -1
        for w in word:
            if w not in char_to_index_lst:
                return False
            else:
                w_index_lst = char_to_index_lst[w]
                # find in w_index that just greater to prev_index
                w_index = self.findLargerElement(w_index_lst, prev_index)
                if w_index == -1:
                    return False
                prev_index = w_index
                # if we can't find, return False
        
        return True


if __name__ == '__main__':
    print(Solution().numMatchingSubseq("abcde", ["a","bb","acd","ace"]))