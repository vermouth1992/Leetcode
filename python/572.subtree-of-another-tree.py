#
# @lc app=leetcode id=572 lang=python3
#
# [572] Subtree of Another Tree
#
# https://leetcode.com/problems/subtree-of-another-tree/description/
#
# algorithms
# Easy (44.61%)
# Total Accepted:    320.4K
# Total Submissions: 718K
# Testcase Example:  '[3,4,5,1,2]\n[4,1,2]'
#
# Given the roots of two binary trees root and subRoot, return true if there is
# a subtree of root with the same structure and node values of subRoot and
# false otherwise.
# 
# A subtree of a binary tree tree is a tree that consists of a node in tree and
# all of this node's descendants. The tree tree could also be considered as a
# subtree of itself.
# 
# 
# Example 1:
# 
# 
# Input: root = [3,4,5,1,2], subRoot = [4,1,2]
# Output: true
# 
# 
# Example 2:
# 
# 
# Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
# Output: false
# 
# 
# 
# Constraints:
# 
# 
# The number of nodes in the root tree is in the range [1, 2000].
# The number of nodes in the subRoot tree is in the range [1, 1000].
# -10^4 <= root.val <= 10^4
# -10^4 <= subRoot.val <= 10^4
# 
# 
#
# Definition for a binary tree node.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isSubtree(self, root: TreeNode, subRoot: TreeNode) -> bool:
        if subRoot is None:
            return True
        queue = [root]
        while len(queue) > 0:
            node = queue.pop()
            if self.isEqualtree(node, subRoot):
                return True
            if node.left is not None:
                queue.append(node.left)
            if node.right is not None:
                queue.append(node.right)
        return False

    def isEqualtree(self, node1: TreeNode, node2: TreeNode) -> bool:
        if node1 is None:
            if node2 is None:
                return True
            else:
                return False
        else:
            if node2 is None:
                return False
            else:
                return node1.val == node2.val and self.isEqualtree(node1.left, node2.left) and self.isEqualtree(node1.right, node2.right)
