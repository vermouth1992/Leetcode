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

        
