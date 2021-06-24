#
# @lc app=leetcode id=450 lang=python3
#
# [450] Delete Node in a BST
#
# https://leetcode.com/problems/delete-node-in-a-bst/description/
#
# algorithms
# Medium (45.80%)
# Total Accepted:    179.2K
# Total Submissions: 389.4K
# Testcase Example:  '[5,3,6,2,4,null,7]\n3'
#
# Given a root node reference of a BST and a key, delete the node with the
# given key in the BST. Return the root node reference (possibly updated) of
# the BST.
# 
# Basically, the deletion can be divided into two stages:
# 
# 
# Search for a node to remove.
# If the node is found, delete the node.
# 
# 
# Follow up: Can you solve it with time complexity O(height of tree)?
# 
# 
# Example 1:
# 
# 
# Input: root = [5,3,6,2,4,null,7], key = 3
# Output: [5,4,6,2,null,null,7]
# Explanation: Given key to delete is 3. So we find the node with value 3 and
# delete it.
# One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
# Please notice that another valid answer is [5,2,6,null,4,null,7] and it's
# also accepted.
# 
# 
# 
# Example 2:
# 
# 
# Input: root = [5,3,6,2,4,null,7], key = 0
# Output: [5,3,6,2,4,null,7]
# Explanation: The tree does not contain a node with value = 0.
# 
# 
# Example 3:
# 
# 
# Input: root = [], key = 0
# Output: []
# 
# 
# 
# Constraints:
# 
# 
# The number of nodes in the tree is in the range [0, 10^4].
# -10^5 <= Node.val <= 10^5
# Each node has a unique value.
# root is a valid binary search tree.
# -10^5 <= key <= 10^5
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
    def deleteNode(self, root: TreeNode, key: int) -> TreeNode:
        # find the node. Move the left node up. Attach the right node to the rightmost node of the left node
        dummy_node = TreeNode(val=-1, left=root, right=None)
        self.deleteNodeHelper(dummy_node, root, key, 'left')
        root = dummy_node.left
        del dummy_node
        return root

    def deleteNodeHelper(self, parent: TreeNode, root: TreeNode, key: int, direction: str):
        if root is None:
            return

        if root.val == key:
            # assign left node
            if direction == 'left':
                if root.left is None:
                    parent.left = root.right
                else:
                    parent.left = root.left
                    node = root.left
                    while node.right is not None:
                        node = node.right
                    # assign right node
                    node.right = root.right
            else:
                if root.right is None:
                    parent.right = root.left
                else:
                    parent.right = root.right
                    node = root.right
                    while node.left is not None:
                        node = node.left
                    node.left = root.left
            
            del root

        elif root.val < key:
            self.deleteNodeHelper(root, root.right, key, 'right')
        else:
            self.deleteNodeHelper(root, root.left, key, 'left')