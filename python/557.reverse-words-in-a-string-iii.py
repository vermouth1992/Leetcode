#
# @lc app=leetcode id=557 lang=python3
#
# [557] Reverse Words in a String III
#
# https://leetcode.com/problems/reverse-words-in-a-string-iii/description/
#
# algorithms
# Easy (72.83%)
# Total Accepted:    263K
# Total Submissions: 360.9K
# Testcase Example:  `"Let's take LeetCode contest"`
#
# Given a string s, reverse the order of characters in each word within a
# sentence while still preserving whitespace and initial word order.
# 
# 
# Example 1:
# Input: s = "Let's take LeetCode contest"
# Output: "s'teL ekat edoCteeL tsetnoc"
# Example 2:
# Input: s = "God Ding"
# Output: "doG gniD"
# 
# 
# Constraints:
# 
# 
# 1 <= s.length <= 5 * 10^4
# s contains printable ASCII characters.
# s does not contain any leading or trailing spaces.
# There is at least one word in s.
# All the words in s are separated by a single space.
# 
# 
#
class Solution:
    def reverseWords(self, s: str) -> str:
        output = ''
        last_index = 0
        for i in range(len(s)):
            if s[i] == ' ':
                for j in range(i - 1, last_index - 1, -1):
                    output += s[j]
                output += ' '
                last_index = i + 1
        if last_index != len(s):
            for j in range(len(s) - 1, last_index - 1, -1):
                output += s[j]

        return output
