#
# @lc app=leetcode id=525 lang=python3
#
# [525] Contiguous Array
#
# https://leetcode.com/problems/contiguous-array/description/
#
# algorithms
# Medium (43.78%)
# Total Accepted:    190.7K
# Total Submissions: 434.7K
# Testcase Example:  '[0,1]'
#
# Given a binary array nums, return the maximum length of a contiguous subarray
# with an equal number of 0 and 1.
# 
# 
# Example 1:
# 
# 
# Input: nums = [0,1]
# Output: 2
# Explanation: [0, 1] is the longest contiguous subarray with an equal number
# of 0 and 1.
# 
# 
# Example 2:
# 
# 
# Input: nums = [0,1,0]
# Output: 2
# Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal
# number of 0 and 1.
# 
# 
# 
# Constraints:
# 
# 
# 1 <= nums.length <= 10^5
# nums[i] is either 0 or 1.
# 
# 
#

from typing import List

class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        # store a dictionary mapping from cumulative sum to index. Equal number of 0 and 1 means the sum is length // 2
        cumulative_sum_to_idx = dict()
        cumulative_sum = 0
        max_length = 0
        for i in range(len(nums)):
            if nums[i] == 1:
                cumulative_sum += 1
            elif nums[i] == 0:
                cumulative_sum += -1

            if cumulative_sum == 0:
                max_length = max(max_length, i + 1)

            if cumulative_sum not in cumulative_sum_to_idx:
                cumulative_sum_to_idx[cumulative_sum] = i
            else:
                max_length = max(max_length, i - cumulative_sum_to_idx[cumulative_sum])

        return max_length