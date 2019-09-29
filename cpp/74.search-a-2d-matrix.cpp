/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 *
 * https://leetcode.com/problems/search-a-2d-matrix/description/
 *
 * algorithms
 * Medium (35.21%)
 * Total Accepted:    250.8K
 * Total Submissions: 710.6K
 * Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,50]]\n3'
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 * 
 * 
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the
 * previous row.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 3
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 13
 * Output: false
 * 
 */

#include "common.hpp"

class Solution {
    // find row inside [low, high)
    size_t findRow(vector<vector<int>>& matrix, int target, size_t rowIndexLow, size_t rowIndexHigh) {
        // base case
        if (rowIndexHigh - rowIndexLow <= 1) return rowIndexLow;
        size_t rowIndexMiddle = (rowIndexLow + rowIndexHigh) / 2;
        if (matrix[rowIndexMiddle][0] == target) {
            return rowIndexMiddle;
        } else if (matrix[rowIndexMiddle][0] < target) {
            return findRow(matrix, target, rowIndexMiddle, rowIndexHigh);
        } else {
            return findRow(matrix, target, rowIndexLow, rowIndexMiddle);
        }
    }

    bool findInsideRow(vector<int> &row, int target, size_t low, size_t high) {
        if (high - low <= 1) {
            return target == row[low];
        }
        size_t middle = (low + high) / 2;
        if (row[middle] == target) {
            return true;
        } else if (row[middle] < target) {
            return findInsideRow(row, target, middle, high);
        } else {
            return findInsideRow(row, target, low, middle);
        }
    }

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        size_t m = matrix.size();
        size_t n = matrix[0].size();
        if (n == 0) return false;
        if (target < matrix[0][0] || target > matrix[m - 1][n - 1]) return false;
        // find the row of the target
        size_t rowIndex = findRow(matrix, target, 0, m);
        return findInsideRow(matrix[rowIndex], target, 0, n);
    }
};
