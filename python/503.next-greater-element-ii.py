#
# @lc app=leetcode id=503 lang=python3
#
# [503] Next Greater Element II
#
# https://leetcode.com/problems/next-greater-element-ii/description/
#
# algorithms
# Medium (59.13%)
# Total Accepted:    141K
# Total Submissions: 238.5K
# Testcase Example:  '[1,2,1]'
#
# Given a circular integer array nums (i.e., the next element of
# nums[nums.length - 1] is nums[0]), return the next greater number for every
# element in nums.
# 
# The next greater number of a number x is the first greater number to its
# traversing-order next in the array, which means you could search circularly
# to find its next greater number. If it doesn't exist, return -1 for this
# number.
# 
# 
# Example 1:
# 
# 
# Input: nums = [1,2,1]
# Output: [2,-1,2]
# Explanation: The first 1's next greater number is 2; 
# The number 2 can't find next greater number. 
# The second 1's next greater number needs to search circularly, which is also
# 2.
# 
# 
# Example 2:
# 
# 
# Input: nums = [1,2,3,4,3]
# Output: [2,3,4,-1,4]
# 
# 
# 
# Constraints:
# 
# 
# 1 <= nums.length <= 10^4
# -10^9 <= nums[i] <= 10^9
# 
# 
#

from typing import List

class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        outputs = [0 for _ in range(len(nums))]
        stack = []
        # we would like to start iterating from the next element after the maximum one
        max_index = 0
        max_element = nums[0]
        for i, num in enumerate(nums):
            if num > max_element:
                max_index = i
                max_element = num

        idx_list = []
        for i in range(max_index + 1, len(nums)):
            idx_list.append(i)
        for i in range(0, max_index + 1):
            idx_list.append(i)

        for i in idx_list:
            num = nums[i]
            if len(stack) == 0:
                stack.append((i, num))
            else:
                while len(stack) > 0:
                    top_idx, top_num = stack[-1]
                    if top_num < num:
                        outputs[top_idx] = num
                        stack.pop()
                    else:
                        break
                stack.append((i, num))

        while len(stack) > 0:
            top_idx, top_num = stack.pop()
            outputs[top_idx] = -1

        return outputs
                

if __name__ == '__main__':
    outputs = Solution().nextGreaterElements([1,2,3,4,3])
    print(outputs)