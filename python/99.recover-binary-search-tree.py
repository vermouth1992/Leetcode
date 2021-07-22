#
# @lc app=leetcode id=99 lang=python3
#
# [99] Recover Binary Search Tree
#
# https://leetcode.com/problems/recover-binary-search-tree/description/
#
# algorithms
# Medium (43.15%)
# Total Accepted:    218.7K
# Total Submissions: 502.9K
# Testcase Example:  '[1,3,null,null,2]'
#
# You are given the root of a binary search tree (BST), where exactly two nodes
# of the tree were swapped by mistake. Recover the tree without changing its
# structure.
# 
# Follow up: A solution using O(n) space is pretty straight forward. Could you
# devise a constant space solution?
# 
# 
# Example 1:
# 
# 
# Input: root = [1,3,null,null,2]
# Output: [3,1,null,null,2]
# Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3
# makes the BST valid.
# 
# 
# Example 2:
# 
# 
# Input: root = [3,1,4,null,null,2]
# Output: [2,1,4,null,null,3]
# Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2
# and 3 makes the BST valid.
# 
# 
# 
# Constraints:
# 
# 
# The number of nodes in the tree is in the range [2, 1000].
# -2^31 <= Node.val <= 2^31 - 1
# 
# 
#
# Definition for a binary tree node.
from typing import List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    def __repr__(self):
        return f'TreeNode(val={self.val}, left={repr(self.left)}, right={repr(self.right)})'

class Solution:
    def recoverTree(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        if root is None:
            return
        # pre-order traversal to obtain the node in sorted order
        order = []
        self.preorder(root, order)
        reverse_index = []
        for i in range(len(order) - 1):
            if order[i + 1].val < order[i].val:
                reverse_index.append((order[i], order[i + 1]))
        
        if len(reverse_index) == 1:
            prev, next = reverse_index[0]
        elif len(reverse_index) == 2:
            prev = reverse_index[0][0]
            next = reverse_index[1][1]
        else:
            raise

        prev.val, next.val = next.val, prev.val


    def preorder(self, root: TreeNode, order: List[TreeNode]) -> None:
        if root.left is not None:
            self.preorder(root.left, order)
        order.append(root)
        if root.right is not None:
            self.preorder(root.right, order)

        

if __name__ == '__main__':
    root = TreeNode(val=3, left=None, right=TreeNode(val=2, right=TreeNode(val=1)))
    print(root)
    Solution().recoverTree(root)
    print(root)
    