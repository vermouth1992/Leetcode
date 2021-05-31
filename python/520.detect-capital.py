#
# @lc app=leetcode id=520 lang=python3
#
# [520] Detect Capital
#
# https://leetcode.com/problems/detect-capital/description/
#
# algorithms
# Easy (54.16%)
# Total Accepted:    194.2K
# Total Submissions: 358.6K
# Testcase Example:  '"USA"'
#
# We define the usage of capitals in a word to be right when one of the
# following cases holds:
# 
# 
# All letters in this word are capitals, like "USA".
# All letters in this word are not capitals, like "leetcode".
# Only the first letter in this word is capital, like "Google".
# 
# 
# Given a string word, return true if the usage of capitals in it is right.
# 
# 
# Example 1:
# Input: word = "USA"
# Output: true
# Example 2:
# Input: word = "FlaG"
# Output: false
# 
# 
# Constraints:
# 
# 
# 1 <= word.length <= 100
# word consists of lowercase and uppercase English letters.
# 
# 
#
class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        if len(word) == 1:
            return True
        
        if word[0].islower():
            for i in range(1, len(word)):
                if word[i].isupper():
                    return False
            return True
        else:
            if word[1].islower():
                for i in range(2, len(word)):
                    if word[i].isupper():
                        return False
                return True
            else:
                for i in range(2, len(word)):
                    if word[i].islower():
                        return False
                return True