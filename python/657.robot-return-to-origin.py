#
# @lc app=leetcode id=657 lang=python3
#
# [657] Robot Return to Origin
#
# https://leetcode.com/problems/robot-return-to-origin/description/
#
# algorithms
# Easy (74.23%)
# Total Accepted:    288.7K
# Total Submissions: 388.7K
# Testcase Example:  '"UD"'
#
# There is a robot starting at position (0, 0), the origin, on a 2D plane.
# Given a sequence of its moves, judge if this robot ends up at (0, 0) after it
# completes its moves.
# 
# The move sequence is represented by a string, and the character moves[i]
# represents its ith move. Valid moves are R (right), L (left), U (up), and D
# (down). If the robot returns to the origin after it finishes all of its
# moves, return true. Otherwise, return false.
# 
# Note: The way that the robot is "facing" is irrelevant. "R" will always make
# the robot move to the right once, "L" will always make it move left, etc.
# Also, assume that the magnitude of the robot's movement is the same for each
# move.
# 
# 
# Example 1:
# 
# 
# Input: moves = "UD"
# Output: true
# Explanation: The robot moves up once, and then down once. All moves have the
# same magnitude, so it ended up at the origin where it started. Therefore, we
# return true.
# 
# 
# Example 2:
# 
# 
# Input: moves = "LL"
# Output: false
# Explanation: The robot moves left twice. It ends up two "moves" to the left
# of the origin. We return false because it is not at the origin at the end of
# its moves.
# 
# 
# Example 3:
# 
# 
# Input: moves = "RRDD"
# Output: false
# 
# 
# Example 4:
# 
# 
# Input: moves = "LDRRLRUULR"
# Output: false
# 
# 
# 
# Constraints:
# 
# 
# 1 <= moves.length <= 2 * 10^4
# moves only contains the characters 'U', 'D', 'L' and 'R'.
# 
# 
#
class Solution:
    def judgeCircle(self, moves: str) -> bool:
        num_L = 0
        num_R = 0
        num_U = 0
        num_D = 0

        for s in moves:
            if s == 'L':
                num_L += 1
            elif s == 'U':
                num_U += 1
            elif s == 'R':
                num_R += 1
            elif s == 'D':
                num_D += 1

        return (num_L == num_R) and (num_U == num_D)
