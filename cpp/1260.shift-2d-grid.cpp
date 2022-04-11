/*
 * @lc app=leetcode id=1260 lang=cpp
 *
 * [1260] Shift 2D Grid
 *
 * https://leetcode.com/problems/shift-2d-grid/description/
 *
 * algorithms
 * Easy (61.79%)
 * Total Accepted:    76K
 * Total Submissions: 111.6K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]\n1'
 *
 * Given a 2D grid of size m x n and an integer k. You need to shift the grid k
 * times.
 * 
 * In one shift operation:
 * 
 * 
 * Element at grid[i][j] moves to grid[i][j + 1].
 * Element at grid[i][n - 1] moves to grid[i + 1][0].
 * Element at grid[m - 1][n - 1] moves to grid[0][0].
 * 
 * 
 * Return the 2D grid after applying shift operation k times.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 1
 * Output: [[9,1,2],[3,4,5],[6,7,8]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]], k = 4
 * Output: [[12,0,21,13],[3,8,1,9],[19,7,2,5],[4,6,11,10]]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 9
 * Output: [[1,2,3],[4,5,6],[7,8,9]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m <= 50
 * 1 <= n <= 50
 * -1000 <= grid[i][j] <= 1000
 * 0 <= k <= 100
 * 
 * 
 */

#include "common.hpp"

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid.at(0).size();
        int new_x = k / n;
        int new_y = k % n;
        vector<vector<int>> result(m, vector<int>(n, 0));
        std::pair<int, int> current = std::make_pair(new_x, new_y);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result[current.first][current.second] = grid[i][j];
                current = this->get_next(current, m, n);
            }
        }
        return result;
    }

private:
    std::pair<int, int> get_next(const std::pair<int, int> &loc, int m, int n) {
        // get the next location
        int x = loc.first;
        int y = loc.second;
        if (y != n - 1) {
            return std::make_pair(x, y + 1);
        } else {
            if (x != m - 1) {
                return std::make_pair(x + 1, 0);
            } else {
                return std::make_pair(0, 0);
            }
        }
    }
};
