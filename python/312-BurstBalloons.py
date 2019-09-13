#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Note: 
(1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
(2) 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

Example:

Given [3, 1, 5, 8]

Return 167

    nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
   coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
"""

"""
The recurrence formula is opt(i, j) = opt(i, k-1) + opt(k+1, j) + f(k) * left * right,
where left and right should be initialized
"""

class Solution(object):
    def maxCoins(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        >>> nums = [3, 1, 5, 8]
        >>> Solution().maxCoins(nums)
        167
        """
        nums = [1] + nums + [1]
        vec = [[0 for i in range(len(nums))] for i in range(len(nums))]
        for i in range(1, len(nums) - 1):
            vec[i][i] = nums[i - 1] * nums[i] * nums[i + 1]
        for diff in range(1, len(nums)):
            for i in range(1, len(nums) - diff - 1):
                left, right = nums[i - 1], nums[i+diff + 1]
                for k in range(i, i+diff+1):
                    current = vec[i][k-1] + vec[k+1][i+diff] + nums[k] * left * right
                    if current > vec[i][i+diff]:
                        vec[i][i+diff] = current
        return vec[1][len(nums) - 2]

