"""
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
"""

"""
opt(l, i) = min(opt(l - 1, i - 1), opt(l - 1, i)) + v(l, i)
Note that we only need to keep two level values
A better solution would be to apply this reversely from bottom to top.
"""


class Solution(object):
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        >>> a = [[2],[3,4],[6,5,7],[4,1,8,3]]
        >>> Solution().minimumTotal(a)
        11
        >>> a = [[-10]]
        >>> Solution().minimumTotal(a)
        -10
        """
        num_level = len(triangle)
        num_elements_last_level = len(triangle[num_level - 1])
        upper_level_opt = [0 for i in range(num_elements_last_level)]
        current_level_opt = [0 for i in range(num_elements_last_level)]
        upper_level_opt[0] = triangle[0][0]
        for level in range(1, len(triangle)):
            for element_index in range(len(triangle[level])):
                if element_index == 0:
                    current_level_opt[element_index] = upper_level_opt[element_index]
                elif element_index == len(triangle[level]) - 1:
                    current_level_opt[element_index] = upper_level_opt[element_index - 1]
                else:
                    current_level_opt[element_index] = min(upper_level_opt[element_index - 1], upper_level_opt[element_index])
                current_level_opt[element_index] += triangle[level][element_index]
            temp = current_level_opt
            current_level_opt = upper_level_opt
            upper_level_opt = temp
        return min(upper_level_opt)



