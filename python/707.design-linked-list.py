#
# @lc app=leetcode id=707 lang=python3
#
# [707] Design Linked List
#
# https://leetcode.com/problems/design-linked-list/description/
#
# algorithms
# Medium (26.23%)
# Total Accepted:    119.9K
# Total Submissions: 455.7K
# Testcase Example:  '["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]\n' +
#  '[[],[1],[3],[1,2],[1],[1],[1]]'
#
# Design your implementation of the linked list. You can choose to use a singly
# or doubly linked list.
# A node in a singly linked list should have two attributes: val and next. val
# is the value of the current node, and next is a pointer/reference to the next
# node.
# If you want to use the doubly linked list, you will need one more attribute
# prev to indicate the previous node in the linked list. Assume all nodes in
# the linked list are 0-indexed.
# 
# Implement the MyLinkedList class:
# 
# 
# MyLinkedList() Initializes the MyLinkedList object.
# int get(int index) Get the value of the index^th node in the linked list. If
# the index is invalid, return -1.
# void addAtHead(int val) Add a node of value val before the first element of
# the linked list. After the insertion, the new node will be the first node of
# the linked list.
# void addAtTail(int val) Append a node of value val as the last element of the
# linked list.
# void addAtIndex(int index, int val) Add a node of value val before the
# index^th node in the linked list. If index equals the length of the linked
# list, the node will be appended to the end of the linked list. If index is
# greater than the length, the node will not be inserted.
# void deleteAtIndex(int index) Delete the index^th node in the linked list, if
# the index is valid.
# 
# 
# 
# Example 1:
# 
# 
# Input
# ["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get",
# "deleteAtIndex", "get"]
# [[], [1], [3], [1, 2], [1], [1], [1]]
# Output
# [null, null, null, null, 2, null, 3]
# 
# Explanation
# MyLinkedList myLinkedList = new MyLinkedList();
# myLinkedList.addAtHead(1);
# myLinkedList.addAtTail(3);
# myLinkedList.addAtIndex(1, 2);    // linked list becomes 1->2->3
# myLinkedList.get(1);              // return 2
# myLinkedList.deleteAtIndex(1);    // now the linked list is 1->3
# myLinkedList.get(1);              // return 3
# 
# 
# 
# Constraints:
# 
# 
# 0 <= index, val <= 1000
# Please do not use the built-in LinkedList library.
# At most 2000 calls will be made to get, addAtHead, addAtTail, addAtIndex and
# deleteAtIndex.
# 
# 
#


class Node:
    def __init__(self, val: int, prev=None, next=None) -> None:
        self.val = val
        self.prev = prev
        self.next = next

    def setPrev(self, prev):
        self.prev = prev

    def setNext(self, next):
        self.next = next

class MyLinkedList:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.head = Node(val=-1, prev=None, next=None)
        self.tail = Node(val=-1, prev=self.head, next=None)
        self.head.setNext(self.tail)
        self.size = 0

    def _insertAfterNode(self, node: Node, val: int):
        newNode = Node(val=val, prev=node, next=node.next)
        node.next.prev = newNode
        node.next = newNode
        

    def get(self, index: int) -> int:
        """
        Get the value of the index-th node in the linked list. If the index is invalid, return -1.
        """
        if index >= self.size:
            return -1

        if index < self.size // 2:
            node = self.head.next
            for _ in range(index):
                node = node.next
            return node.val
        else:
            node = self.tail.prev
            for _ in range(self.size - index - 1):
                node = node.prev
            return node.val
        

    def addAtHead(self, val: int) -> None:
        """
        Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
        """
        self._insertAfterNode(self.head, val=val)
        self.size += 1
        

    def addAtTail(self, val: int) -> None:
        """
        Append a node of value val to the last element of the linked list.
        """
        self._insertAfterNode(self.tail.prev, val=val)
        self.size += 1
        

    def addAtIndex(self, index: int, val: int) -> None:
        """
        Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
        """
        if index > self.size:
            return

        if index > self.size // 2:
            node = self.head
            for _ in range(index):
                node = node.next
        else:
            node = self.tail
            for _ in range(self.size - index + 1):
                node = node.prev

        self._insertAfterNode(node, val)
        self.size += 1
        

    def deleteAtIndex(self, index: int) -> None:
        """
        Delete the index-th node in the linked list, if the index is valid.
        """
        if index >= self.size:
            return

        if index > self.size // 2:
            node = self.head
            for _ in range(index):
                node = node.next
        else:
            node = self.tail
            for _ in range(self.size - index + 1):
                node = node.prev
        
        # delete the node after node
        deletedNode = node.next
        deletedNode.next.prev = node
        node.next = deletedNode.next
        del deletedNode

        self.size -= 1


# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)
