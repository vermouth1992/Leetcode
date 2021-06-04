#
# @lc app=leetcode id=599 lang=python3
#
# [599] Minimum Index Sum of Two Lists
#
# https://leetcode.com/problems/minimum-index-sum-of-two-lists/description/
#
# algorithms
# Easy (52.13%)
# Total Accepted:    116.2K
# Total Submissions: 222.6K
# Testcase Example:  '["Shogun","Tapioca Express","Burger King","KFC"]\n' +
  '["Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"]'
#
# Suppose Andy and Doris want to choose a restaurant for dinner, and they both
# have a list of favorite restaurants represented by strings.
# 
# You need to help them find out their common interest with the least list
# index sum. If there is a choice tie between answers, output all of them with
# no order requirement. You could assume there always exists an answer.
# 
# 
# Example 1:
# 
# 
# Input: list1 = ["Shogun","Tapioca Express","Burger King","KFC"], list2 =
# ["Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"]
# Output: ["Shogun"]
# Explanation: The only restaurant they both like is "Shogun".
# 
# 
# Example 2:
# 
# 
# Input: list1 = ["Shogun","Tapioca Express","Burger King","KFC"], list2 =
# ["KFC","Shogun","Burger King"]
# Output: ["Shogun"]
# Explanation: The restaurant they both like and have the least index sum is
# "Shogun" with index sum 1 (0+1).
# 
# 
# Example 3:
# 
# 
# Input: list1 = ["Shogun","Tapioca Express","Burger King","KFC"], list2 =
# ["KFC","Burger King","Tapioca Express","Shogun"]
# Output: ["KFC","Burger King","Tapioca Express","Shogun"]
# 
# 
# Example 4:
# 
# 
# Input: list1 = ["Shogun","Tapioca Express","Burger King","KFC"], list2 =
# ["KNN","KFC","Burger King","Tapioca Express","Shogun"]
# Output: ["KFC","Burger King","Tapioca Express","Shogun"]
# 
# 
# Example 5:
# 
# 
# Input: list1 = ["KFC"], list2 = ["KFC"]
# Output: ["KFC"]
# 
# 
# 
# Constraints:
# 
# 
# 1 <= list1.length, list2.length <= 1000
# 1 <= list1[i].length, list2[i].length <= 30
# list1[i] and list2[i] consist of spaces ' ' and English letters.
# All the stings of list1 are unique.
# All the stings of list2 are unique.
# 
# 

from typing import List

class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        list1_key_to_idx = dict()
        for i, key in enumerate(list1):
            list1_key_to_idx[key] = i
        list2_key_to_idx = dict()
        for i, key in enumerate(list2):
            list2_key_to_idx[key] = i
        
        least_index_sum_key = []
        least_sum = len(list1) + len(list2)

        for key, index in list1_key_to_idx.items():
            if key in list2_key_to_idx:
                curr_sum = index + list2_key_to_idx[key]
                if curr_sum < least_sum:
                    least_sum = curr_sum
                    least_index_sum_key = [key]
                elif curr_sum == least_sum:
                    least_index_sum_key.append(key)

        return least_index_sum_key