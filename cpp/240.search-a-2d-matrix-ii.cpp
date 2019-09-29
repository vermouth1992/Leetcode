/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 *
 * https://leetcode.com/problems/search-a-2d-matrix-ii/description/
 *
 * algorithms
 * Medium (41.37%)
 * Total Accepted:    210.6K
 * Total Submissions: 507.4K
 * Testcase Example:  '[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]\n' +
  '5'
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 * 
 * 
 * Integers in each row are sorted in ascending from left to right.
 * Integers in each column are sorted in ascending from top to bottom.
 * 
 * 
 * Example:
 * 
 * Consider the following matrix:
 * 
 * 
 * [
 * ⁠ [1,   4,  7, 11, 15],
 * ⁠ [2,   5,  8, 12, 19],
 * ⁠ [3,   6,  9, 16, 22],
 * ⁠ [10, 13, 14, 17, 24],
 * ⁠ [18, 21, 23, 26, 30]
 * ]
 * 
 * 
 * Given target = 5, return true.
 * 
 * Given target = 20, return false.
 * 
 */

#include "common.hpp"

class Solution {
private:
    bool searchMatrixHelper(vector<vector<int>>& matrix, int target, size_t rowLow, 
                size_t rowHigh, size_t columnLow, size_t columnHigh) {

        if (target < matrix[rowLow][columnLow] || target > matrix[rowHigh - 1][columnHigh - 1]) return false;

        size_t rowMiddle = (rowLow + rowHigh) / 2;
        size_t columnMiddle = (columnLow + columnHigh) / 2;
        if (rowHigh - rowLow <= 1) {
            if (columnHigh - columnLow <= 1) {
                return matrix[rowLow][columnLow] == target;
            } else {
                if (matrix[rowLow][columnMiddle] == target) {
                    return true;
                } else if (matrix[rowLow][columnMiddle] < target) {
                    return searchMatrixHelper(matrix, target, rowLow, rowHigh, columnMiddle, columnHigh);
                } else {
                    return searchMatrixHelper(matrix, target, rowLow, rowHigh, columnLow, columnMiddle);
                }
            }
        } else {
            if (columnHigh - columnLow <= 1) {
                if (matrix[rowMiddle][columnLow] == target) {
                    return true;
                } else if (matrix[rowMiddle][columnLow] < target) {
                    return searchMatrixHelper(matrix, target, rowMiddle, rowHigh, columnLow, columnHigh);
                } else {
                    return searchMatrixHelper(matrix, target, rowLow, rowMiddle, columnLow, columnHigh);
                }
            } else {
                // split again into four parts
                if (searchMatrixHelper(matrix, target, rowLow, rowMiddle, columnLow, columnMiddle)) {
                    return true;
                }
                if (searchMatrixHelper(matrix, target, rowLow, rowMiddle, columnMiddle, columnHigh)) {
                    return true;
                }
                if (searchMatrixHelper(matrix, target, rowMiddle, rowHigh, columnLow, columnMiddle)) {
                    return true;
                }
                if (searchMatrixHelper(matrix, target, rowMiddle, rowHigh, columnMiddle, columnHigh)) {
                    return true;
                }
                return false;
            }
        }
    }

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        size_t m = matrix.size();
        size_t n = matrix[0].size();
        if (n == 0) return false;
        // divide and conquer. split the matrix into 4 parts
        return searchMatrixHelper(matrix, target, 0, m, 0, n);
    }
};
