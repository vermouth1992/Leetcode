#
# @lc app=leetcode id=501 lang=python3
#
# [501] Find Mode in Binary Search Tree
#
# https://leetcode.com/problems/find-mode-in-binary-search-tree/description/
#
# algorithms
# Easy (44.17%)
# Total Accepted:    111.6K
# Total Submissions: 252.8K
# Testcase Example:  '[1,null,2,2]'
#
# Given the root of a binary search tree (BST) with duplicates, return all the
# mode(s) (i.e., the most frequently occurred element) in it.
# 
# If the tree has more than one mode, return them in any order.
# 
# Assume a BST is defined as follows:
# 
# 
# The left subtree of a node contains only nodes with keys less than or equal
# to the node's key.
# The right subtree of a node contains only nodes with keys greater than or
# equal to the node's key.
# Both the left and right subtrees must also be binary search trees.
# 
# 
# 
# Example 1:
# 
# 
# Input: root = [1,null,2,2]
# Output: [2]
# 
# 
# Example 2:
# 
# 
# Input: root = [0]
# Output: [0]
# 
# 
# 
# Constraints:
# 
# 
# The number of nodes in the tree is in the range [1, 10^4].
# -10^5 <= Node.val <= 10^5
# 
# 
# 
# Follow up: Could you do that without using any extra space? (Assume that the
# implicit stack space incurred due to recursion does not count).
#
# Definition for a binary tree node.

from typing import Dict, List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def findMode(self, root: TreeNode) -> List[int]:
        freq = {} # map from val to frequencies
        self.findNodeHelper(root, freq)
        # find the most frequent elements in freq
        modes = []
        max_freq = -1
        for val, curr_freq in freq.items():
            if curr_freq > max_freq:
                modes = [val]
                max_freq = curr_freq
            elif curr_freq == max_freq:
                modes.append(val)

        return modes


    def findNodeHelper(self, root: TreeNode, freq: Dict[int, int]):
        if root is None:
            return

        if root.val not in freq:
            freq[root.val] = 0
        
        freq[root.val] += 1

        self.findNodeHelper(root.left, freq)
        self.findNodeHelper(root.right, freq)
