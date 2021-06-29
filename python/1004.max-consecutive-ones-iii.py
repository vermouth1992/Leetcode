#
# @lc app=leetcode id=1004 lang=python3
#
# [1004] Max Consecutive Ones III
#
# https://leetcode.com/problems/max-consecutive-ones-iii/description/
#
# algorithms
# Medium (61.14%)
# Total Accepted:    120.4K
# Total Submissions: 196.6K
# Testcase Example:  '[1,1,1,0,0,0,1,1,1,1,0]\n2'
#
# Given a binary array nums and an integer k, return the maximum number of
# consecutive 1's in the array if you can flip at most k 0's.
# 
# 
# Example 1:
# 
# 
# Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
# Output: 6
# Explanation: [1,1,1,0,0,1,1,1,1,1,1]
# Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
# 
# Example 2:
# 
# 
# Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
# Output: 10
# Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
# Bolded numbers were flipped from 0 to 1. The longest subarray is
# underlined.
# 
# 
# 
# Constraints:
# 
# 
# 1 <= nums.length <= 10^5
# nums[i] is either 0 or 1.
# 0 <= k <= nums.length
# 
# 
#

from typing import List

class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        # find the next ones. slide right to fill all the o's and compute the length of 1's.
        starting_ones_pos = []
        consecutive_ones = False
        current_pos = []
        for i, num in enumerate(nums):
            if num == 1:
                if not consecutive_ones:
                    current_pos.append(i)
                    consecutive_ones = True
            else:
                if consecutive_ones:
                    current_pos.append(i)
                    consecutive_ones = False
                    starting_ones_pos.append(current_pos)
                    current_pos = []
        
        if consecutive_ones:
            current_pos.append(len(nums))
            starting_ones_pos.append(current_pos)

        if len(starting_ones_pos) == 0:
            return k

        max_length = -1
        for i, pos in enumerate(starting_ones_pos):
            start, end = pos
            current_length = end - start
            left_reverse = k
            for j in range(i + 1, len(starting_ones_pos)):
                next_start, next_end = starting_ones_pos[j]
                interval = next_start - end
                if interval > left_reverse:
                    # not enough reverse to connect the next ones
                    current_length += left_reverse
                    left_reverse = 0
                    break
                else:
                    current_length = current_length + interval + next_end - next_start
                    start, end = next_start, next_end
                    left_reverse -= interval

            # print(current_length)
            # there are still left_reverse after we fill the last 
            current_length = min(current_length + left_reverse, len(nums))
            max_length = max(max_length, current_length)
        return max_length


if __name__ == '__main__':
    print(Solution().longestOnes([1,1,1,0,0,0,1,1,1,1,0], 2))
    print(Solution().longestOnes([0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], 3))
    print(Solution().longestOnes([1,1,1,0,0,0,1,1,1,1], 0))

