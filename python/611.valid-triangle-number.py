#
# @lc app=leetcode id=611 lang=python3
#
# [611] Valid Triangle Number
#
# https://leetcode.com/problems/valid-triangle-number/description/
#
# algorithms
# Medium (49.68%)
# Total Accepted:    86.1K
# Total Submissions: 173.3K
# Testcase Example:  '[2,2,3,4]'
#
# Given an integer array nums, return the number of triplets chosen from the
# array that can make triangles if we take them as side lengths of a
# triangle.
# 
# 
# Example 1:
# 
# 
# Input: nums = [2,2,3,4]
# Output: 3
# Explanation: Valid combinations are: 
# 2,3,4 (using the first 2)
# 2,3,4 (using the second 2)
# 2,2,3
# 
# 
# Example 2:
# 
# 
# Input: nums = [4,2,3,4]
# Output: 4
# 
# 
# 
# Constraints:
# 
# 
# 1 <= nums.length <= 1000
# 0 <= nums[i] <= 1000
# 
# 
#

from typing import List

class Solution:
    def triangleNumber(self, nums: List[int]) -> int:
        if len(nums) < 3:
            return 0
        nums = sorted(nums)
        total = 0
        for i in range(len(nums) - 2):
            if nums[i] > 0:
                k = i + 2
                for j in range(i + 1, len(nums) - 1):
                    while k < len(nums) and nums[i] + nums[j] > nums[k]:
                        k += 1
                    total += k - j - 1

        return total
