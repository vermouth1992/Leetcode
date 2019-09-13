#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

"""

class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        char_map = {}
        current_start_index = 0
        current_max_length = 0
        for i, char in enumerate(s):
            if char in char_map:
                last_index = char_map[char]
                if last_index >= current_start_index:
                    # repeated character
                    current_length = i - current_start_index
                    if current_length > current_max_length:
                        current_max_length = current_length
                    current_start_index = last_index + 1
            char_map[char] = i
        if len(s) - current_start_index > current_max_length:
            current_max_length = len(s) - current_start_index
        return current_max_length

if __name__ == '__main__':
    assert(Solution().lengthOfLongestSubstring("abcabcbb") == 3)
    assert(Solution().lengthOfLongestSubstring("bbbbb") == 1)
    assert(Solution().lengthOfLongestSubstring("pwwkew") == 3)
