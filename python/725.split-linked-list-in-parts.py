#
# @lc app=leetcode id=725 lang=python3
#
# [725] Split Linked List in Parts
#
# https://leetcode.com/problems/split-linked-list-in-parts/description/
#
# algorithms
# Medium (53.36%)
# Total Accepted:    62.7K
# Total Submissions: 117.2K
# Testcase Example:  '[1,2,3]\n5'
#
# Given the head of a singly linked list and an integer k, split the linked
# list into k consecutive linked list parts.
# 
# The length of each part should be as equal as possible: no two parts should
# have a size differing by more than one. This may lead to some parts being
# null.
# 
# The parts should be in the order of occurrence in the input list, and parts
# occurring earlier should always have a size greater than or equal to parts
# occurring later.
# 
# Return an array of the k parts.
# 
# 
# Example 1:
# 
# 
# Input: head = [1,2,3], k = 5
# Output: [[1],[2],[3],[],[]]
# Explanation:
# The first element output[0] has output[0].val = 1, output[0].next = null.
# The last element output[4] is null, but its string representation as a
# ListNode is [].
# 
# 
# Example 2:
# 
# 
# Input: head = [1,2,3,4,5,6,7,8,9,10], k = 3
# Output: [[1,2,3,4],[5,6,7],[8,9,10]]
# Explanation:
# The input has been split into consecutive parts with size difference at most
# 1, and earlier parts are a larger size than the later parts.
# 
# 
# 
# Constraints:
# 
# 
# The number of nodes in the list is in the range [0, 1000].
# 0 <= Node.val <= 1000
# 1 <= k <= 50
# 
# 
#
# Definition for singly-linked list.

from typing import List

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def splitListToParts(self, head: ListNode, k: int) -> List[ListNode]:
        length = self.computeListLength(head)
        elements = length // k
        numExtraParts = length % k
        output = []
        prev = None
        for i in range(k):
            output.append(head)
            for _ in range(elements):
                prev = head
                head = head.next
            if i < numExtraParts:
                prev = head
                head = head.next
            if prev is not None:
                prev.next = None

        return output


    def computeListLength(self, head: ListNode) -> int:
        length = 0
        while head is not None:
            head = head.next
            length += 1
        return length
