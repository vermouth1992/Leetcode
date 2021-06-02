#
# @lc app=leetcode id=560 lang=python3
#
# [560] Subarray Sum Equals K
#
# https://leetcode.com/problems/subarray-sum-equals-k/description/
#
# algorithms
# Medium (43.72%)
# Total Accepted:    493K
# Total Submissions: 1.1M
# Testcase Example:  '[1,1,1]\n2'
#
# Given an array of integers nums and an integer k, return the total number of
# continuous subarrays whose sum equals to k.
# 
# 
# Example 1:
# Input: nums = [1,1,1], k = 2
# Output: 2
# Example 2:
# Input: nums = [1,2,3], k = 3
# Output: 2
# 
# 
# Constraints:
# 
# 
# 1 <= nums.length <= 2 * 10^4
# -1000 <= nums[i] <= 1000
# -10^7 <= k <= 10^7
# 
# 
#

from typing import List

class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        # sum of i to j = sum[0:j] - sum[0:i], O(nlogn)
        cumulative_to_idxes = {}
        cumulative_sum = 0
        output = 0
        for num in nums:
            cumulative_sum += num
            rest = cumulative_sum - k
            if rest == 0:
                output += 1
            
            output += cumulative_to_idxes.get(rest, 0)
            if cumulative_sum not in cumulative_to_idxes:
                cumulative_to_idxes[cumulative_sum] = 0
            cumulative_to_idxes[cumulative_sum] += 1
        
        return output