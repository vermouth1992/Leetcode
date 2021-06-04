#
# @lc app=leetcode id=605 lang=python3
#
# [605] Can Place Flowers
#
# https://leetcode.com/problems/can-place-flowers/description/
#
# algorithms
# Easy (31.63%)
# Total Accepted:    176.8K
# Total Submissions: 559.2K
# Testcase Example:  '[1,0,0,0,1]\n1'
#
# You have a long flowerbed in which some of the plots are planted, and some
# are not. However, flowers cannot be planted in adjacent plots.
# 
# Given an integer array flowerbed containing 0's and 1's, where 0 means empty
# and 1 means not empty, and an integer n, return if n new flowers can be
# planted in the flowerbed without violating the no-adjacent-flowers rule.
# 
# 
# Example 1:
# Input: flowerbed = [1,0,0,0,1], n = 1
# Output: true
# Example 2:
# Input: flowerbed = [1,0,0,0,1], n = 2
# Output: false
# 
# 
# Constraints:
# 
# 
# 1 <= flowerbed.length <= 2 * 10^4
# flowerbed[i] is 0 or 1.
# There are no two adjacent flowers in flowerbed.
# 0 <= n <= flowerbed.length
# 
# 
#

from typing import List

class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        num_spots = 0
        index = 0
        while index < len(flowerbed):
            if flowerbed[index] == 0:
                # last position
                if index == len(flowerbed) - 1:
                    num_spots += 1
                    index += 1
                # current is zero and next is also zero
                elif flowerbed[index + 1] == 0:
                    num_spots += 1
                    index += 2
                # current is zero and next is 1. must be 010
                else:
                    index += 3
            else:
                # 10
                index += 2
        return num_spots >= n