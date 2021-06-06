#
# @lc app=leetcode id=637 lang=python3
#
# [637] Average of Levels in Binary Tree
#
# https://leetcode.com/problems/average-of-levels-in-binary-tree/description/
#
# algorithms
# Easy (66.42%)
# Total Accepted:    200.1K
# Total Submissions: 301K
# Testcase Example:  '[3,9,20,null,null,15,7]'
#
# Given the root of a binary tree, return the average value of the nodes on
# each level in the form of an array. Answers within 10^-5 of the actual answer
# will be accepted.
# 
# Example 1:
# 
# 
# Input: root = [3,9,20,null,15,7]
# Output: [3.00000,14.50000,11.00000]
# Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5,
# and on level 2 is 11.
# Hence return [3, 14.5, 11].
# 
# 
# Example 2:
# 
# 
# Input: root = [3,9,20,15,7]
# Output: [3.00000,14.50000,11.00000]
# 
# 
# 
# Constraints:
# 
# 
# The number of nodes in the tree is in the range [1, 10^4].
# -2^31 <= Node.val <= 2^31 - 1
# 
# 
#
# Definition for a binary tree node.

from typing import List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def averageOfLevels(self, root: TreeNode) -> List[float]:
        current_level = [root]
        output = []
        while True:
            current_sum = [node.val for node in current_level]
            current_sum = sum(current_sum) / len(current_sum)
            output.append(current_sum)
            next_level = []
            while len(current_level) > 0:
                node = current_level.pop()
                if node.left is not None:
                    next_level.append(node.left)
                if node.right is not None:
                    next_level.append(node.right)
            if len(next_level) == 0:
                break
            else:
                current_level = next_level
        return output

