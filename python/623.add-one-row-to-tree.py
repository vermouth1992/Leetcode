#
# @lc app=leetcode id=623 lang=python3
#
# [623] Add One Row to Tree
#
# https://leetcode.com/problems/add-one-row-to-tree/description/
#
# algorithms
# Medium (53.10%)
# Total Accepted:    71.3K
# Total Submissions: 134.2K
# Testcase Example:  '[4,2,6,3,1,5]\n1\n2'
#
# Given the root of a binary tree and two integers val and depth, add a row of
# nodes with value val at the given depth depth.
# 
# Note that the root node is at depth 1.
# 
# The adding rule is:
# 
# 
# Given the integer depth, for each not null tree node cur at the depth depth -
# 1, create two tree nodes with value val as cur's left subtree root and right
# subtree root.
# cur's original left subtree should be the left subtree of the new left
# subtree root.
# cur's original right subtree should be the right subtree of the new right
# subtree root.
# If depth == 1 that means there is no depth depth - 1 at all, then create a
# tree node with value val as the new root of the whole original tree, and the
# original tree is the new root's left subtree.
# 
# 
# 
# Example 1:
# 
# 
# Input: root = [4,2,6,3,1,5], val = 1, depth = 2
# Output: [4,1,1,2,null,null,6,3,1,5]
# 
# 
# Example 2:
# 
# 
# Input: root = [4,2,null,3,1], val = 1, depth = 3
# Output: [4,2,null,1,1,3,null,null,1]
# 
# 
# 
# Constraints:
# 
# 
# The number of nodes in the tree is in the range [1, 10^4].
# The depth of the tree is in the range [1, 10^4].
# -100 <= Node.val <= 100
# -10^5 <= val <= 10^5
# 1 <= depth <= the depth of tree + 1
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
    def addOneRow(self, root: TreeNode, val: int, depth: int) -> TreeNode:
        if depth == 1:
            new_root = TreeNode(val=val, left=root)
            return new_root

        # find all the nodes at depth
        curr_row = [root]
        for _ in range(depth - 2):
            next_row = []
            while len(curr_row) > 0:
                curr_node = curr_row.pop()
                if curr_node.left is not None:
                    next_row.append(curr_node.left)
                if curr_node.right is not None:
                    next_row.append(curr_node.right)
            curr_row = next_row

        for node in curr_row:
            new_left_node = TreeNode(val=val, left=node.left)
            new_right_node = TreeNode(val=val, left=None, right=node.right)
            node.left = new_left_node
            node.right = new_right_node

        return root