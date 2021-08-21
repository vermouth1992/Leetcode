/*
 * @lc app=leetcode id=1289 lang=cpp
 *
 * [1289] Minimum Falling Path Sum II
 *
 * https://leetcode.com/problems/minimum-falling-path-sum-ii/description/
 *
 * algorithms
 * Hard (62.75%)
 * Total Accepted:    20.3K
 * Total Submissions: 32.2K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given an n x n integer matrix grid, return the minimum sum of a falling path
 * with non-zero shifts.
 * 
 * A falling path with non-zero shifts is a choice of exactly one element from
 * each row of grid such that no two elements chosen in adjacent rows are in
 * the same column.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [[1,2,3],[4,5,6],[7,8,9]]
 * Output: 13
 * Explanation: 
 * The possible falling paths are:
 * [1,5,9], [1,5,7], [1,6,7], [1,6,8],
 * [2,4,8], [2,4,9], [2,6,7], [2,6,8],
 * [3,4,8], [3,4,9], [3,5,7], [3,5,9]
 * The falling path with the smallest sum is [1,5,7], so the answer is 13.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [[7]]
 * Output: 7
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == grid.length == grid[i].length
 * 1 <= n <= 200
 * -99 <= grid[i][j] <= 99
 * 
 * 
 */

#include "common.hpp"

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        // we can compute the minimum and the second minimum element in an row so that we reduce the time
        // complexity from O(N^3) to O(N^2).
        int n = grid.size();
        vector<vector<int>> dp (n, vector<int> (n, 0));
        for (int i = 0; i < n; i++) {
            // last row
            dp.at(n - 1).at(i) = grid.at(n - 1).at(i);
        }
        for (int row = n - 2; row >= 0; row--) {
            // compute the minimum element and second minimum element and the minimum index
            int min_index = 0;
            int min_val = dp.at(row + 1).at(0);
            int second_min_val = -1;
            if (dp.at(row + 1).at(1) < min_val) {
                min_index = 1;
                min_val = dp.at(row + 1).at(1);
                second_min_val = dp.at(row + 1).at(0);
            } else {
                second_min_val = dp.at(row + 1).at(1);
            }
            for (int i = 2; i < n; i++) {
                if (dp.at(row + 1).at(i) < min_val) {
                    min_index = i;
                    second_min_val = min_val;
                    min_val = dp.at(row + 1).at(i);
                } else if (dp.at(row + 1).at(i) < second_min_val) {
                    second_min_val = dp.at(row + 1).at(i);
                }
            }            
            for (int col = 0; col < n; col++) {
                if (col == min_index) {
                    dp.at(row).at(col) = second_min_val + grid.at(row).at(col);
                } else {
                    dp.at(row).at(col) = min_val + grid.at(row).at(col);
                }
            }
        }
        return *std::min_element(dp.at(0).begin(), dp.at(0).end());
    }
};
