#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. 
Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution and you may not use the same element twice.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
"""

"""
使用2个指针，一开始分别指向第一个数和最后一个数，当两者之和小于target时，左指针右移，当两者之和大于target时，右指针左移
时间：O(n)，空间：O(1), 可能有O(log n)的解法吗？？？
类似问题：653. Two Sum IV - Input is a BST
"""

class Solution(object):
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        leftPointer, rightPointer = 1, len(numbers)
        while leftPointer < rightPointer:
            currentSum = numbers[leftPointer - 1] + numbers[rightPointer - 1]
            if currentSum < target:
                leftPointer += 1
            elif currentSum == target:
                return [leftPointer, rightPointer]
            else:
                rightPointer -= 1
        return None 


if __name__ == '__main__':
    # for sanity check
    nums = [2, 7, 11, 15]
    assert(Solution().twoSum(nums, 9) == [1, 2])