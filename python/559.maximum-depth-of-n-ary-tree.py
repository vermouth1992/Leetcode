#
# @lc app=leetcode id=559 lang=python3
#
# [559] Maximum Depth of N-ary Tree
#
# https://leetcode.com/problems/maximum-depth-of-n-ary-tree/description/
#
# algorithms
# Easy (69.76%)
# Total Accepted:    164.6K
# Total Submissions: 235.9K
# Testcase Example:  '[1,null,3,2,4,null,5,6]'
#
# Given a n-ary tree, find its maximum depth.
# 
# The maximum depth is the number of nodes along the longest path from the root
# node down to the farthest leaf node.
# 
# Nary-Tree input serialization is represented in their level order traversal,
# each group of children is separated by the null value (See examples).
# 
# 
# Example 1:
# 
# 
# 
# 
# Input: root = [1,null,3,2,4,null,5,6]
# Output: 3
# 
# 
# Example 2:
# 
# 
# 
# 
# Input: root =
# [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
# Output: 5
# 
# 
# 
# Constraints:
# 
# 
# The depth of the n-ary tree is less than or equal to 1000.
# The total number of nodes is between [0, 10^4].
# 
# 
#


# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children


class Solution:
    def maxDepth(self, root: Node) -> int:
        if root is None:
            return 0
        currentLevel = [root]
        nextLevel = []
        depth = 1
        while True:
            while len(currentLevel) > 0:
                node = currentLevel.pop()
                for child in node.children:
                    nextLevel.append(child)
            if len(nextLevel) == 0:
                return depth
            else:
                depth += 1
                currentLevel = nextLevel
                nextLevel = []
