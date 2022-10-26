/*
 * @lc app=leetcode id=836 lang=cpp
 *
 * [836] Rectangle Overlap
 *
 * https://leetcode.com/problems/rectangle-overlap/description/
 *
 * algorithms
 * Easy (42.99%)
 * Total Accepted:    85.1K
 * Total Submissions: 198.4K
 * Testcase Example:  '[0,0,2,2]\n[1,1,3,3]'
 *
 * An axis-aligned rectangle is represented as a list [x1, y1, x2, y2], where
 * (x1, y1) is the coordinate of its bottom-left corner, and (x2, y2) is the
 * coordinate of its top-right corner. Its top and bottom edges are parallel to
 * the X-axis, and its left and right edges are parallel to the Y-axis.
 * 
 * Two rectangles overlap if the area of their intersection is positive. To be
 * clear, two rectangles that only touch at the corner or edges do not
 * overlap.
 * 
 * Given two axis-aligned rectangles rec1 and rec2, return true if they
 * overlap, otherwise return false.
 * 
 * 
 * Example 1:
 * Input: rec1 = [0,0,2,2], rec2 = [1,1,3,3]
 * Output: true
 * Example 2:
 * Input: rec1 = [0,0,1,1], rec2 = [1,0,2,1]
 * Output: false
 * Example 3:
 * Input: rec1 = [0,0,1,1], rec2 = [2,2,3,3]
 * Output: false
 * 
 * 
 * Constraints:
 * 
 * 
 * rect1.length == 4
 * rect2.length == 4
 * -10^9 <= rec1[i], rec2[i] <= 10^9
 * rec1 and rec2 represent a valid rectangle with a non-zero area.
 * 
 * 
 */

#include "common.hpp"

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x11 = rec1[0]; // bottom-left corner
        int y11 = rec1[1];
        int x21 = rec1[2]; // top-right corner
        int y21 = rec1[3];
        
        int x12 = rec2[0]; // bottom-left corner
        int y12 = rec2[1];
        int x22 = rec2[2]; // top-right corner
        int y22 = rec2[3];
        
        // up
        if (y12 >= y21 || x12 >= x21 || y22 <= y11 || x22 <= x11) {
            return false;
        }
        return true;
    }
};
