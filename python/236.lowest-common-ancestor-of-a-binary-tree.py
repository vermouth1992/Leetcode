#
# @lc app=leetcode id=236 lang=python3
#
# [236] Lowest Common Ancestor of a Binary Tree
#
# https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
#
# algorithms
# Medium (50.03%)
# Total Accepted:    697.1K
# Total Submissions: 1.4M
# Testcase Example:  '[3,5,1,6,2,0,8,null,null,7,4]\n5\n1'
#
# Given a binary tree, find the lowest common ancestor (LCA) of two given nodes
# in the tree.
# 
# According to the definition of LCA on Wikipedia: “The lowest common ancestor
# is defined between two nodes p and q as the lowest node in T that has both p
# and q as descendants (where we allow a node to be a descendant of
# itself).”
# 
# 
# Example 1:
# 
# 
# Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
# Output: 3
# Explanation: The LCA of nodes 5 and 1 is 3.
# 
# 
# Example 2:
# 
# 
# Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
# Output: 5
# Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant
# of itself according to the LCA definition.
# 
# 
# Example 3:
# 
# 
# Input: root = [1,2], p = 1, q = 2
# Output: 1
# 
# 
# 
# Constraints:
# 
# 
# The number of nodes in the tree is in the range [2, 10^5].
# -10^9 <= Node.val <= 10^9
# All Node.val are unique.
# p != q
# p and q will exist in the tree.
# 
# 
#
# Definition for a binary tree node.

from typing import Tuple


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        return self.lowestCommonAncestorHelper(root, p, q)[0]

    def lowestCommonAncestorHelper(self, root: TreeNode, p: TreeNode, q: TreeNode) -> Tuple[TreeNode, bool]:
        if root is None:
            return None, False

        if root.val == p.val or root.val == q.val:
            mid = True
        else:
            mid = False

        left_ans, left = self.lowestCommonAncestorHelper(root.left, p, q)

        if left_ans is not None:
            return left_ans, True

        right_ans, right = self.lowestCommonAncestorHelper(root.right, p, q)

        if right_ans is not None:
            return right_ans, True

        # the least common ancestor have exactly two True's
        if left + right + mid == 2:
            return root, True

        contain_p_or_q = left or right or mid
        return None, contain_p_or_q
        

