#
# @lc app=leetcode id=697 lang=python3
#
# [697] Degree of an Array
#
# https://leetcode.com/problems/degree-of-an-array/description/
#
# algorithms
# Easy (54.67%)
# Total Accepted:    113.3K
# Total Submissions: 207.1K
# Testcase Example:  '[1,2,2,3,1]'
#
# Given a non-empty array of non-negative integers nums, the degree of this
# array is defined as the maximum frequency of any one of its elements.
# 
# Your task is to find the smallest possible length of a (contiguous) subarray
# of nums, that has the same degree as nums.
# 
# 
# Example 1:
# 
# 
# Input: nums = [1,2,2,3,1]
# Output: 2
# Explanation: 
# The input array has a degree of 2 because both elements 1 and 2 appear twice.
# Of the subarrays that have the same degree:
# [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
# The shortest length is 2. So return 2.
# 
# 
# Example 2:
# 
# 
# Input: nums = [1,2,2,3,1,4,2]
# Output: 6
# Explanation: 
# The degree is 3 because the element 2 is repeated 3 times.
# So [2,2,3,1,4,2] is the shortest subarray, therefore returning 6.
# 
# 
# 
# Constraints:
# 
# 
# nums.length will be between 1 and 50,000.
# nums[i] will be an integer between 0 and 49,999.
# 
# 
#

from typing import List

class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
        # for each number, store its frequency as well as it first and last appearance
        freq = dict()
        appearance = dict()
        for i, num in enumerate(nums):
            if num not in freq:
                freq[num] = 0
                appearance[num] = [i, i]
            freq[num] += 1
            if i > appearance[num][1]:
                appearance[num][1] = i

        # find the degree
        max_freq = 0
        max_freq_num = []

        for num, freq in freq.items():
            if freq > max_freq:
                max_freq_num = [num]
                max_freq = freq
            elif freq == max_freq:
                max_freq_num.append(num)

        length = []
        for num in max_freq_num:
            length.append(appearance[num][1] - appearance[num][0] + 1)

        return min(length)
