#
# @lc app=leetcode id=524 lang=python3
#
# [524] Longest Word in Dictionary through Deleting
#
# https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/description/
#
# algorithms
# Medium (50.20%)
# Total Accepted:    107.4K
# Total Submissions: 213.8K
# Testcase Example:  '"abpcplea"\n["ale","apple","monkey","plea"]'
#
# Given a string s and a string array dictionary, return the longest string in
# the dictionary that can be formed by deleting some of the given string
# characters. If there is more than one possible result, return the longest
# word with the smallest lexicographical order. If there is no possible result,
# return the empty string.
# 
# 
# Example 1:
# 
# 
# Input: s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
# Output: "apple"
# 
# 
# Example 2:
# 
# 
# Input: s = "abpcplea", dictionary = ["a","b","c"]
# Output: "a"
# 
# 
# 
# Constraints:
# 
# 
# 1 <= s.length <= 1000
# 1 <= dictionary.length <= 1000
# 1 <= dictionary[i].length <= 1000
# s and dictionary[i] consist of lowercase English letters.
# 
# 
#

from typing import List

class Solution:
    def findLongestWord(self, s: str, dictionary: List[str]) -> str:
        max_str = ""
        for target in dictionary:
            if self.isSubstring(s, target):
                if len(max_str) == 0:
                    max_str = target
                # compare s and max_str
                elif len(target) > len(max_str):
                    max_str = target
                elif len(target) == len(max_str):
                    for i in range(len(target)):
                        if target[i] < max_str[i]:
                            max_str = target
                            break
                        elif target[i] > max_str[i]:
                            break
        return max_str

    def isSubstring(self, s: str, target: str) -> bool:
        # return whether target can be formed by s by deleting some chars
        pointer_s = 0
        pointer_target = 0
        while pointer_s < len(s):
            if s[pointer_s] == target[pointer_target]:
                pointer_s += 1
                pointer_target += 1
            else:
                pointer_s += 1

            if pointer_target == len(target):
                return True

        return False


