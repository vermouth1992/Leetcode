#
# @lc app=leetcode id=92 lang=python3
#
# [92] Reverse Linked List II
#
# https://leetcode.com/problems/reverse-linked-list-ii/description/
#
# algorithms
# Medium (41.06%)
# Total Accepted:    371K
# Total Submissions: 892.8K
# Testcase Example:  '[1,2,3,4,5]\n2\n4'
#
# Given the head of a singly linked list and two integers left and right where
# left <= right, reverse the nodes of the list from position left to position
# right, and return the reversed list.
# 
# 
# Example 1:
# 
# 
# Input: head = [1,2,3,4,5], left = 2, right = 4
# Output: [1,4,3,2,5]
# 
# 
# Example 2:
# 
# 
# Input: head = [5], left = 1, right = 1
# Output: [5]
# 
# 
# 
# Constraints:
# 
# 
# The number of nodes in the list is n.
# 1 <= n <= 500
# -500 <= Node.val <= 500
# 1 <= left <= right <= n
# 
# 
# 
# Follow up: Could you do it in one pass?
#
# Definition for singly-linked list.

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseBetween(self, head: ListNode, left: int, right: int) -> ListNode:
        # create a dummy head to simplify the process
        dummy_head = ListNode(val=0, next=head)
        node = head
        prev_node = dummy_head
        for _ in range(1, left):
            prev_node = node
            node = node.next

        start_prev_node = prev_node
        start_node = node

        for _ in range(left, right + 1):
            next_node = node.next
            node.next = prev_node
            prev_node = node
            node = next_node

        start_prev_node.next = prev_node
        start_node.next = node

        head = dummy_head.next
        del dummy_head

        return head

