#
# @lc app=leetcode id=628 lang=python3
#
# [628] Maximum Product of Three Numbers
#
# https://leetcode.com/problems/maximum-product-of-three-numbers/description/
#
# algorithms
# Easy (46.70%)
# Total Accepted:    156.7K
# Total Submissions: 335.6K
# Testcase Example:  '[1,2,3]'
#
# Given an integer array nums, find three numbers whose product is maximum and
# return the maximum product.
# 
# 
# Example 1:
# Input: nums = [1,2,3]
# Output: 6
# Example 2:
# Input: nums = [1,2,3,4]
# Output: 24
# Example 3:
# Input: nums = [-1,-2,-3]
# Output: -6
# 
# 
# Constraints:
# 
# 
# 3 <= nums.length <= 10^4
# -1000 <= nums[i] <= 1000
# 
# 
#

from typing import List

class Solution:
    def maximumProduct(self, nums: List[int]) -> int:
        nums = sorted(nums)
        out = nums[-3] * nums[-2] * nums[-1]
        if nums[-1] <= 0 or nums[0] >= 0:
            return out

        out1 = nums[0] * nums[1] * nums[-1]
        return max(out, out1)
