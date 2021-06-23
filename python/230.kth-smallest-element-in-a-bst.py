#
# @lc app=leetcode id=230 lang=python3
#
# [230] Kth Smallest Element in a BST
#
# https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
#
# algorithms
# Medium (63.44%)
# Total Accepted:    558.9K
# Total Submissions: 877.1K
# Testcase Example:  '[3,1,4,null,2]\n1'
#
# Given the root of a binary search tree, and an integer k, return the k^th
# (1-indexed) smallest element in the tree.
# 
# 
# Example 1:
# 
# 
# Input: root = [3,1,4,null,2], k = 1
# Output: 1
# 
# 
# Example 2:
# 
# 
# Input: root = [5,3,6,2,4,null,null,1], k = 3
# Output: 3
# 
# 
# 
# Constraints:
# 
# 
# The number of nodes in the tree is n.
# 1 <= k <= n <= 10^4
# 0 <= Node.val <= 10^4
# 
# 
# 
# Follow up: If the BST is modified often (i.e., we can do insert and delete
# operations) and you need to find the kth smallest frequently, how would you
# optimize?
#
# Definition for a binary tree node.

from typing import List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        data = [k]
        return self.kthSmallestHelper(root, data)


    def kthSmallestHelper(self, root: TreeNode, data: List[int]):
        if root.left is not None:
            val = self.kthSmallestHelper(root.left, data)
            if val is not None:
                return val

        # inorder traversal
        data[0] = data[0] - 1

        if data[0] == 0:
            return root.val

        if root.right is not None:
            val = self.kthSmallestHelper(root.right, data)
            if val is not None:
                return val

        return None