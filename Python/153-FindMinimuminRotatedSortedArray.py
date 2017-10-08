"""
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
"""

class Solution(object):
    def findMinHelper(self, nums, start_index, end_index):
        if nums[start_index] < nums[end_index]:
            return nums[start_index]
        if end_index - start_index == 1:
            return min(nums[start_index], nums[end_index])
        middle_index = (start_index + end_index) // 2
        if nums[middle_index] < nums[start_index]:
            return self.findMinHelper(nums, start_index, middle_index)
        else:
            return self.findMinHelper(nums, middle_index, end_index)

    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        >>> Solution().findMin([4, 5])
        4
        """
        if len(nums) == 1:
            return nums[0]
        else:
            return self.findMinHelper(nums, 0, len(nums) - 1)
