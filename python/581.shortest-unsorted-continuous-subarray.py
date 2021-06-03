#
# @lc app=leetcode id=581 lang=python3
#
# [581] Shortest Unsorted Continuous Subarray
#
# https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/
#
# algorithms
# Medium (33.09%)
# Total Accepted:    181.4K
# Total Submissions: 548K
# Testcase Example:  '[2,6,4,8,10,9,15]'
#
# Given an integer array nums, you need to find one continuous subarray that if
# you only sort this subarray in ascending order, then the whole array will be
# sorted in ascending order.
# 
# Return the shortest such subarray and output its length.
# 
# 
# Example 1:
# 
# 
# Input: nums = [2,6,4,8,10,9,15]
# Output: 5
# Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the
# whole array sorted in ascending order.
# 
# 
# Example 2:
# 
# 
# Input: nums = [1,2,3,4]
# Output: 0
# 
# 
# Example 3:
# 
# 
# Input: nums = [1]
# Output: 0
# 
# 
# 
# Constraints:
# 
# 
# 1 <= nums.length <= 10^4
# -10^5 <= nums[i] <= 10^5
# 
# 
# 
# Follow up: Can you solve it in O(n) time complexity?
#

from typing import List

class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        # find left pivot and right pivot
        left_pivot = -1
        for i in range(len(nums) - 1):
            if nums[i] > nums[i + 1]:
                left_pivot = i
                break
        if left_pivot == -1:
            return 0

        right_pivot = -1
        for i in range(len(nums) - 1, 0, -1):
            if (nums[i] < nums[i - 1]):
                right_pivot = i
                break

        # the left pivot must be smaller than the smallest in the unsorted array
        min_unsorted = min(nums[left_pivot:right_pivot + 1])
        max_unsorted = max(nums[left_pivot:right_pivot + 1])

        while left_pivot > 0 and nums[left_pivot - 1] > min_unsorted:
            left_pivot -= 1

        while right_pivot < len(nums) - 1 and nums[right_pivot + 1] < max_unsorted:
            right_pivot += 1

        return right_pivot - left_pivot + 1
        

if __name__ == '__main__':
    print(Solution().findUnsortedSubarray([2, 1]))