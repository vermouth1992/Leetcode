#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
"""

"""
想法: 使用1个辅助哈希表作一遍遍历，哈希表中记录(target - 当前数 -> 当前下标)。这样，当下一个遍历的数存在哈希表中，即可返回答案
性能分析：时间 O(n), 空间 O(n), already optimal
类似问题 167. Two Sum II - Input array is sorted
"""


class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        helperHashTable = dict()
        for i in xrange(len(nums)):
            leftNumber = target - nums[i]
            if nums[i] in helperHashTable:
                return [helperHashTable[nums[i]], i]
            else:
                helperHashTable[leftNumber] = i
        return None

if __name__ == '__main__':
    # for sanity check
    nums = [2, 7, 11, 15]
    assert(Solution().twoSum(nums, 9) == [0, 1])