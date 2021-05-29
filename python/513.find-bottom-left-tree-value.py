#
# @lc app=leetcode id=513 lang=python3
#
# [513] Find Bottom Left Tree Value
#
# https://leetcode.com/problems/find-bottom-left-tree-value/description/
#
# algorithms
# Medium (63.07%)
# Total Accepted:    133.5K
# Total Submissions: 211.7K
# Testcase Example:  '[2,1,3]'
#
# Given the root of a binary tree, return the leftmost value in the last row of
# the tree.
# 
# 
# Example 1:
# 
# 
# Input: root = [2,1,3]
# Output: 1
# 
# 
# Example 2:
# 
# 
# Input: root = [1,2,3,4,null,5,6,null,null,7]
# Output: 7
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

from typing import no_type_check


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def findBottomLeftValue(self, root: TreeNode) -> int:
        last_row_values = []
        formal_level_nodes = [root]
        next_level_nodes = []

        while True:
            for node in formal_level_nodes:
                if node.left is not None:
                    next_level_nodes.append(node.left)
                if node.right is not None:
                    next_level_nodes.append(node.right)
            if len(next_level_nodes) == 0:
                break
            else:
                formal_level_nodes = next_level_nodes
                next_level_nodes = []

        return formal_level_nodes[0].val