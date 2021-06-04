#
# @lc app=leetcode id=606 lang=python3
#
# [606] Construct String from Binary Tree
#
# https://leetcode.com/problems/construct-string-from-binary-tree/description/
#
# algorithms
# Easy (55.94%)
# Total Accepted:    105.1K
# Total Submissions: 187.7K
# Testcase Example:  '[1,2,3,4]'
#
# Given the root of a binary tree, construct a string consists of parenthesis
# and integers from a binary tree with the preorder traversing way, and return
# it.
# 
# Omit all the empty parenthesis pairs that do not affect the one-to-one
# mapping relationship between the string and the original binary tree.
# 
# 
# Example 1:
# 
# 
# Input: root = [1,2,3,4]
# Output: "1(2(4))(3)"
# Explanation: Originallay it needs to be "1(2(4)())(3()())", but you need to
# omit all the unnecessary empty parenthesis pairs. And it will be
# "1(2(4))(3)"
# 
# 
# Example 2:
# 
# 
# Input: root = [1,2,3,null,4]
# Output: "1(2()(4))(3)"
# Explanation: Almost the same as the first example, except we cannot omit the
# first parenthesis pair to break the one-to-one mapping relationship between
# the input and the output.
# 
# 
# 
# Constraints:
# 
# 
# The number of nodes in the tree is in the range [1, 10^4].
# -1000 <= Node.val <= 1000
# 
# 
#
# Definition for a binary tree node.

from _typeshed import OpenTextModeUpdating


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def tree2str(self, root: TreeNode) -> str:
        if root is None:
            return ''
        output = str(root.val)
        left_str = self.tree2str(root.left)
        right_str = self.tree2str(root.right)

        if root.left is None:
            if root.right is not None:
                output += '()' + '(' + right_str + ')'
            else:
                return output
        else:
            if root.right is None:
                output += '(' + left_str + ')'
            else:
                output += '(' + left_str + ')' + '(' + right_str + ')'

        return output
