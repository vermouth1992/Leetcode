#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
"""

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        overflow = 0
        answer = None
        workPtr = None
        while l1 is not None and l2 is not None:
            currentNumber = l1.val + l2.val + overflow
            currentDigit = currentNumber % 10
            overflow = currentNumber // 10
            if answer is None:
                answer = ListNode(currentDigit)
                workPtr = answer
            else:
                workPtr.next = ListNode(currentDigit)
                workPtr = workPtr.next
            l1 = l1.next
            l2 = l2.next
        while l1 is not None:
            currentNumber = overflow + l1.val
            currentDigit = currentNumber % 10
            overflow = currentNumber // 10
            workPtr.next = ListNode(currentDigit)
            workPtr = workPtr.next
            l1 = l1.next
        while l2 is not None:
            currentNumber = overflow + l2.val
            currentDigit = currentNumber % 10
            overflow = currentNumber // 10
            workPtr.next = ListNode(currentDigit)
            workPtr = workPtr.next
            l2 = l2.next

        if overflow != 0:
            workPtr.next = ListNode(overflow)
        return answer


if __name__ == '__main__':
    a = ListNode(2)
    a.next = ListNode(4)
    a.next.next = ListNode(9)
    b = ListNode(5)
    b.next = ListNode(6)
    answer = Solution().addTwoNumbers(a, b)
    assert(answer.val == 7 and answer.next.val == 0 and answer.next.next.val == 0 and answer.next.next.next.val == 1)