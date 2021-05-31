#
# @lc app=leetcode id=523 lang=python3
#
# [523] Continuous Subarray Sum
#
# https://leetcode.com/problems/continuous-subarray-sum/description/
#
# algorithms
# Medium (25.11%)
# Total Accepted:    196K
# Total Submissions: 779.9K
# Testcase Example:  '[23,2,4,6,7]\n6'
#
# Given an integer array nums and an integer k, return true if nums has a
# continuous subarray of size at least two whose elements sum up to a multiple
# of k, or false otherwise.
# 
# An integer x is a multiple of k if there exists an integer n such that x = n
# * k. 0 is always a multiple of k.
# 
# 
# Example 1:
# 
# 
# Input: nums = [23,2,4,6,7], k = 6
# Output: true
# Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up
# to 6.
# 
# 
# Example 2:
# 
# 
# Input: nums = [23,2,6,4,7], k = 6
# Output: true
# Explanation: [23, 2, 6, 4, 7] is an continuous subarray of size 5 whose
# elements sum up to 42.
# 42 is a multiple of 6 because 42 = 7 * 6 and 7 is an integer.
# 
# 
# Example 3:
# 
# 
# Input: nums = [23,2,6,4,7], k = 13
# Output: false
# 
# 
# 
# Constraints:
# 
# 
# 1 <= nums.length <= 10^5
# 0 <= nums[i] <= 10^9
# 0 <= sum(nums[i]) <= 2^31 - 1
# 1 <= k <= 2^31 - 1
# 
# 
#

"""
a[i:j] mod k = 0 if a[:j] mod k == a[:i] mod k
"""

from typing import List

class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        # table = [[0 for _ in range(len(nums))] for _ in range(len(nums))]
        # for i in range(len(nums)):
        #     table[i][i] = nums[i]
        
        # # fill in the table
        # for diff in range(1, len(nums)):
        #     for i in range(len(nums) - diff):
        #         table[i][i + diff] = nums[i] + nums[i + diff] + table[i + 1][i + diff - 1]
        #         if table[i][i + diff] % k == 0:
        #             return True
        
        # return False
        mod_vals = dict() # map from mod to index
        sum = 0
        for i in range(len(nums)):
            sum += nums[i]
            mod = sum % k
            if mod == 0 and i > 0:
                return True

            if mod in mod_vals: 
                if i - mod_vals[mod] > 1:
                    return True
            else:
                mod_vals[mod] = i

        return False


if __name__ == '__main__':
    print(Solution().checkSubarraySum([5, 0, 0, 0], 7))

        
