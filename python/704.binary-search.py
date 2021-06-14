#
# @lc app=leetcode id=704 lang=python3
#
# [704] Binary Search
#
# https://leetcode.com/problems/binary-search/description/
#
# algorithms
# Easy (54.56%)
# Total Accepted:    277.8K
# Total Submissions: 508.2K
# Testcase Example:  '[-1,0,3,5,9,12]\n9'
#
# Given an array of integers nums which is sorted in ascending order, and an
# integer target, write a function to search target in nums. If target exists,
# then return its index. Otherwise, return -1.
# 
# You must write an algorithm with O(log n) runtime complexity.
# 
# 
# Example 1:
# 
# 
# Input: nums = [-1,0,3,5,9,12], target = 9
# Output: 4
# Explanation: 9 exists in nums and its index is 4
# 
# 
# Example 2:
# 
# 
# Input: nums = [-1,0,3,5,9,12], target = 2
# Output: -1
# Explanation: 2 does not exist in nums so return -1
# 
# 
# 
# Constraints:
# 
# 
# 1 <= nums.length <= 10^4
# -10^4 < nums[i], target < 10^4
# All the integers in nums are unique.
# nums is sorted in ascending order.
# 
# 
#

from typing import List

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        return self.searchHelper(nums, target, 0, len(nums) - 1)

    def searchHelper(self, nums, target, left_index, right_index):
        if target < nums[left_index]:
            return -1
        if target > nums[right_index]:
            return -1
        
        mid_index = (left_index + right_index) // 2
        if nums[mid_index] == target:
            return mid_index

        if left_index == right_index:
            return -1

        if nums[mid_index] < target:
            return self.searchHelper(nums, target, mid_index + 1, right_index)
        else:
            return self.searchHelper(nums, target, left_index, mid_index - 1)
