#
# @lc app=leetcode id=530 lang=python3
#
# [530] Minimum Absolute Difference in BST
#
# https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/
#
# algorithms
# Easy (55.23%)
# Total Accepted:    115.5K
# Total Submissions: 209K
# Testcase Example:  '[4,2,6,1,3]'
#
# Given the root of a Binary Search Tree (BST), return the minimum absolute
# difference between the values of any two different nodes in the tree.
# 
# 
# Example 1:
# 
# 
# Input: root = [4,2,6,1,3]
# Output: 1
# 
# 
# Example 2:
# 
# 
# Input: root = [1,0,48,null,null,12,49]
# Output: 1
# 
# 
# 
# Constraints:
# 
# 
# The number of nodes in the tree is in the range [2, 10^4].
# 0 <= Node.val <= 10^5
# 
# 
# 
# Note: This question is the same as 783:
# https://leetcode.com/problems/minimum-distance-between-bst-nodes/
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
    def getNodeValues(self, root: TreeNode) -> List[int]:
        value = []
        self.getNodeValuesHelper(root, value)
        return value

    def getNodeValuesHelper(self, root: TreeNode, value: List[int]):
        if root is None:
            return
        value.append(root.val)
        self.getNodeValuesHelper(root.left, value)
        self.getNodeValuesHelper(root.right, value)

    def getMinimumDifference(self, root: TreeNode) -> int:
        # get all the values and put into a list O(n)
        value = self.getNodeValues(root)
        # sort the list O(nlogn)
        value = sorted(value)
        # find the minimum difference between ajacent values O(n)
        min_abs_diff = abs(value[0] - value[1])
        for i in range(1, len(value) - 1):
            diff = abs(value[i] - value[i + 1])
            if diff < min_abs_diff:
                min_abs_diff = diff
        return min_abs_diff
