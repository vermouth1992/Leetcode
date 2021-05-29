#
# @lc app=leetcode id=508 lang=python3
#
# [508] Most Frequent Subtree Sum
#
# https://leetcode.com/problems/most-frequent-subtree-sum/description/
#
# algorithms
# Medium (59.65%)
# Total Accepted:    86.2K
# Total Submissions: 144.5K
# Testcase Example:  '[5,2,-3]'
#
# Given the root of a binary tree, return the most frequent subtree sum. If
# there is a tie, return all the values with the highest frequency in any
# order.
# 
# The subtree sum of a node is defined as the sum of all the node values formed
# by the subtree rooted at that node (including the node itself).
# 
# 
# Example 1:
# 
# 
# Input: root = [5,2,-3]
# Output: [2,-3,4]
# 
# 
# Example 2:
# 
# 
# Input: root = [5,2,-5]
# Output: [2]
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
# Definition for a binary tree node.

# find compute the subtree sum. Then compute the mode using 501.

from typing import Dict, List, no_type_check

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def findFrequentTreeSum(self, root: TreeNode) -> List[int]:
        freq = {}
        self.findFrequentTreeSumHelper(root, freq)
        modes = []
        max_freq = -1
        for val, curr_freq in freq.items():
            if curr_freq > max_freq:
                modes = [val]
                max_freq = curr_freq
            elif curr_freq == max_freq:
                modes.append(val)

        return modes


    def findFrequentTreeSumHelper(self, root: TreeNode, freq: Dict[int, int]) -> int:
        if root is None:
            return 0

        # compute sum recursively
        left_sum = self.findFrequentTreeSumHelper(root.left, freq)
        right_sum = self.findFrequentTreeSumHelper(root.right, freq)

        node_sum = left_sum + right_sum + root.val

        if node_sum not in freq:
            freq[node_sum] = 0

        freq[node_sum] += 1

        return node_sum
