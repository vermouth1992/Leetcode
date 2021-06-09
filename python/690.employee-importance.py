#
# @lc app=leetcode id=690 lang=python3
#
# [690] Employee Importance
#
# https://leetcode.com/problems/employee-importance/description/
#
# algorithms
# Easy (59.33%)
# Total Accepted:    123.1K
# Total Submissions: 206.7K
# Testcase Example:  '[[1,5,[2,3]],[2,3,[]],[3,3,[]]]\n1'
#
# You have a data structure of employee information, which includes the
# employee's unique id, their importance value, and their direct subordinates'
# id.
# 
# You are given an array of employees employees where:
# 
# 
# employees[i].id is the ID of the i^th employee.
# employees[i].importance is the importance value of the i^th employee.
# employees[i].subordinates is a list of the IDs of the subordinates of the
# i^th employee.
# 
# 
# Given an integer id that represents the ID of an employee, return the total
# importance value of this employee and all their subordinates.
# 
# 
# Example 1:
# 
# 
# Input: employees = [[1,5,[2,3]],[2,3,[]],[3,3,[]]], id = 1
# Output: 11
# Explanation: Employee 1 has importance value 5, and he has two direct
# subordinates: employee 2 and employee 3.
# They both have importance value 3.
# So the total importance value of employee 1 is 5 + 3 + 3 = 11.
# 
# 
# Example 2:
# 
# 
# Input: employees = [[1,2,[5]],[5,-3,[]]], id = 5
# Output: -3
# 
# 
# 
# Constraints:
# 
# 
# 1 <= employees.length <= 2000
# 1 <= employees[i].id <= 2000
# All employees[i].id are unique.
# -100 <= employees[i].importance <= 100
# One employee has at most one direct leader and may have several
# subordinates.
# id is guaranteed to be a valid employee id.
# 
# 
#
"""
# Definition for Employee.
class Employee:
    def __init__(self, id: int, importance: int, subordinates: List[int]):
        self.id = id
        self.importance = importance
        self.subordinates = subordinates
"""

class Employee:
    def __init__(self, id: int, importance: int, subordinates: List[int]):
        self.id = id
        self.importance = importance
        self.subordinates = subordinates

from typing import List

class Solution:
    def getImportance(self, employees: List['Employee'], id: int) -> int:
        id_to_employee = dict()
        for e in employees:
            id_to_employee[e.id] = e

        queue = [id_to_employee[id]]
        total_importance = 0
        while len(queue) > 0:
            employee = queue.pop()
            total_importance += employee.importance
            for s in employee.subordinates:
                queue.append(id_to_employee[s])

        return total_importance
        
