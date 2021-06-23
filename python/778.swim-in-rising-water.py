#
# @lc app=leetcode id=778 lang=python3
#
# [778] Swim in Rising Water
#
# https://leetcode.com/problems/swim-in-rising-water/description/
#
# algorithms
# Hard (55.10%)
# Total Accepted:    49.6K
# Total Submissions: 86.3K
# Testcase Example:  '[[0,2],[1,3]]'
#
# On an N x N grid, each square grid[i][j] represents the elevation at that
# point (i,j).
# 
# Now rain starts to fall. At time t, the depth of the water everywhere is t.
# You can swim from a square to another 4-directionally adjacent square if and
# only if the elevation of both squares individually are at most t. You can
# swim infinite distance in zero time. Of course, you must stay within the
# boundaries of the grid during your swim.
# 
# You start at the top left square (0, 0). What is the least time until you can
# reach the bottom right square (N-1, N-1)?
# 
# Example 1:
# 
# 
# Input: [[0,2],[1,3]]
# Output: 3
# Explanation:
# At time 0, you are in grid location (0, 0).
# You cannot go anywhere else because 4-directionally adjacent neighbors have a
# higher elevation than t = 0.
# 
# You cannot reach point (1, 1) until time 3.
# When the depth of water is 3, we can swim anywhere inside the grid.
# 
# 
# Example 2:
# 
# 
# Input:
# [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
# Output: 16
# Explanation:
# ⁠0  1  2  3  4
# 24 23 22 21  5
# 12 13 14 15 16
# 11 17 18 19 20
# 10  9  8  7  6
# 
# The final route is marked in bold.
# We need to wait until time 16 so that (0, 0) and (4, 4) are connected.
# 
# 
# Note:
# 
# 
# 2 <= N <= 50.
# grid[i][j] is a permutation of [0, ..., N*N - 1].
# 
# 
#

from typing import List
import heapq

class PriorityQueue:
    def __init__(self, min_heap=True) -> None:
        self.min_heap = min_heap
        self.storage = []

    def empty(self):
        return len(self.storage) <= 0

    def add(self, item, priority):
        if not self.min_heap:
            priority = -priority
        heapq.heappush(self.storage, (priority, item))

    def pop(self):
        priority, item = heapq.heappop(self.storage)
        if not self.min_heap:
            priority = -priority
        return priority, item

    def top(self):
        priority, item = self.storage[0]
        if not self.min_heap:
            priority = -priority
        return priority, item

class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        explored = set()
        # find all the connected points. Add all the frontiers to a priority queue
        frontiers = PriorityQueue(min_heap=True)
        length = len(grid)
        height = len(grid[0])
        frontiers.add((0, 0), grid[0][0])
        time = grid[0][0]
        prev_priority = grid[0][0]
        while True:
            # step 1: pop all the froniters with the same priority
            search = []
            top_priority, top_item = frontiers.pop()
            search.append(top_item)
            while not frontiers.empty() and frontiers.top()[0] == top_priority:
                _, item = frontiers.pop()
                search.append(item)

            time = time + top_priority - prev_priority
            prev_priority = top_priority
            # step 2: find all the connected positions.
            while len(search) > 0:
                pos = search.pop()

                if pos == (length - 1, height - 1):
                    return time

                explored.add(pos)
                # expand pos
                x, y = pos
                
                expand = [(x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)]
                for x_e, y_e in expand:
                    if (x_e, y_e) not in explored:
                        if x_e >= 0 and x_e < length and y_e >= 0 and y_e < height:
                            if grid[x_e][y_e] <= top_priority:
                                search.append((x_e, y_e)) # add to the explored set
                            else:
                                frontiers.add((x_e, y_e), grid[x_e][y_e])

        
