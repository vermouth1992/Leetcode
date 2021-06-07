#
# @lc app=leetcode id=643 lang=python3
#
# [643] Maximum Average Subarray I
#
# https://leetcode.com/problems/maximum-average-subarray-i/description/
#
# algorithms
# Easy (42.17%)
# Total Accepted:    103K
# Total Submissions: 243.9K
# Testcase Example:  '[1,12,-5,-6,50,3]\n4'
#
# You are given an integer array nums consisting of n elements, and an integer
# k.
# 
# Find a contiguous subarray whose length is equal to k that has the maximum
# average value and return this value. Any answer with a calculation error less
# than 10^-5 will be accepted.
# 
# 
# Example 1:
# 
# 
# Input: nums = [1,12,-5,-6,50,3], k = 4
# Output: 12.75000
# Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
# 
# 
# Example 2:
# 
# 
# Input: nums = [5], k = 1
# Output: 5.00000
# 
# 
# 
# Constraints:
# 
# 
# n == nums.length
# 1 <= k <= n <= 10^5
# -10^4 <= nums[i] <= 10^4
# 
# 
#

from typing import List

class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        current_head = 0
        current_tail = k
        current_sum = 0
        for i in range(current_head, current_tail):
            current_sum += nums[i]
        max_sum = current_sum

        while current_tail < len(nums):
            print(current_sum)
            current_head += 1
            current_tail += 1
            current_sum = current_sum + nums[current_tail - 1] - nums[current_head - 1]
            if current_sum > max_sum:
                max_sum = current_sum
        
        return max_sum / k

if __name__ == '__main__':
    print(Solution().findMaxAverage([1,12,-5,-6,50,3], 4))