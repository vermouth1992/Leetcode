#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
"""
from __future__ import division

class Solution(object):

    def isEven(self, number):
        return number % 2 == 0

    def findMedian(self, nums):
        length = len(nums)
        if self.isEven(length):
            return (nums[length // 2] + nums[length // 2 + 1]) / 2
        else:
            return nums[length // 2]

    # we have to keep the number of list to always be even or odd
    def cutHalf(self, nums, is_up):
        middle_index = len(nums) // 2
        if isEven(len(nums)):
            if is_up:
                return nums[middle_index:]
            else:
                return nums[0:middle_index]
        else:
            if is_up:
                return nums[middle_index:]
            else:
                return nums[0:middle_index + 1]

    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        median1 = self.findMedian(nums1)
        median2 = self.findMedian(nums2)
        if median1 == median2:
            return median1
        elif median1 > median2:
            return self.findMedianSortedArrays(nums1[len(nums1) // 2:], nums2[0:len(nums2) // 2+1])
        else:
            return self.findMedianSortedArrays(nums1[len(nums1) // 2:], nums2[len(nums2) // 2])







