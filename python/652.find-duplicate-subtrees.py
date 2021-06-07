#
# @lc app=leetcode id=652 lang=python3
#
# [652] Find Duplicate Subtrees
#
# https://leetcode.com/problems/find-duplicate-subtrees/description/
#
# algorithms
# Medium (53.55%)
# Total Accepted:    98.5K
# Total Submissions: 183.6K
# Testcase Example:  '[1,2,3,4,null,2,4,null,null,4]'
#
# Given the root of a binary tree, return all duplicate subtrees.
# 
# For each kind of duplicate subtrees, you only need to return the root node of
# any one of them.
# 
# Two trees are duplicate if they have the same structure with the same node
# values.
# 
# 
# Example 1:
# 
# 
# Input: root = [1,2,3,4,null,2,4,null,null,4]
# Output: [[2,4],[4]]
# 
# 
# Example 2:
# 
# 
# Input: root = [2,1,1]
# Output: [[1]]
# 
# 
# Example 3:
# 
# 
# Input: root = [2,2,2,3,null,3,null]
# Output: [[2,3],[3]]
# 
# 
# 
# Constraints:
# 
# 
# The number of the nodes in the tree will be in the range [1, 10^4]
# -200 <= Node.val <= 200
# 
# 
#
# Definition for a binary tree node.

from typing import Dict, List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def findDuplicateSubtrees(self, root: TreeNode) -> List[TreeNode]:
        subtrees = dict()
        self.serialize(root, subtrees)
        output = []
        for val in subtrees.values():
            if len(val) > 1:
                output.append(val[0])
        return output

    def serialize(self, root: TreeNode, subtrees: Dict[str, List[TreeNode]]):
        if root is None:
            return ''

        left_str = self.serialize(root.left, subtrees)
        right_str = self.serialize(root.right, subtrees)

        current_str = 'LS' + left_str + 'LE' + str(root.val) + 'RS' + right_str + 'RE'
        if current_str not in subtrees:
            subtrees[current_str] = []
        subtrees[current_str].append(root)

        return current_str