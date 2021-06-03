#
# @lc app=leetcode id=594 lang=python3
#
# [594] Longest Harmonious Subsequence
#
# https://leetcode.com/problems/longest-harmonious-subsequence/description/
#
# algorithms
# Easy (51.44%)
# Total Accepted:    97.9K
# Total Submissions: 190.2K
# Testcase Example:  '[1,3,2,2,5,2,3,7]'
#
# We define a harmonious array as an array where the difference between its
# maximum value and its minimum value is exactly 1.
# 
# Given an integer array nums, return the length of its longest harmonious
# subsequence among all its possible subsequences.
# 
# A subsequence of array is a sequence that can be derived from the array by
# deleting some or no elements without changing the order of the remaining
# elements.
# 
# 
# Example 1:
# 
# 
# Input: nums = [1,3,2,2,5,2,3,7]
# Output: 5
# Explanation: The longest harmonious subsequence is [3,2,2,2,3].
# 
# 
# Example 2:
# 
# 
# Input: nums = [1,2,3,4]
# Output: 2
# 
# 
# Example 3:
# 
# 
# Input: nums = [1,1,1,1]
# Output: 0
# 
# 
# 
# Constraints:
# 
# 
# 1 <= nums.length <= 2 * 10^4
# -10^9 <= nums[i] <= 10^9
# 
# 
#

from typing import List

class Solution:
    def findLHS(self, nums: List[int]) -> int:
        num_to_freq = dict()
        for num in nums:
            if num not in num_to_freq:
                num_to_freq[num] = 0
            num_to_freq[num] += 1

        lhs = 0
        for num, freq in num_to_freq.items():
            num_add_one_freq = num_to_freq.get(num + 1, -1)
            if num_add_one_freq != -1:
                curr_lhs = freq + num_add_one_freq
                if curr_lhs > lhs:
                    lhs = curr_lhs
        return lhs
        
