/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 *
 * https://leetcode.com/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (61.24%)
 * Total Accepted:    189.9K
 * Total Submissions: 297.5K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n x n
 * chessboard such that no two queens attack each other.
 * 
 * Given an integer n, return the number of distinct solutions to the n-queens
 * puzzle.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 4
 * Output: 2
 * Explanation: There are two distinct solutions to the 4-queens puzzle as
 * shown.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 1
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 9
 * 
 * 
 */

#include "common.hpp"

class Solution {
public:
    int totalNQueens(int n) {
        int result = 0;
        std::vector<int> current;
        this->dfs(result, current, n);
        return result;
    }

private:
    bool compatible(int row1, int col1, int row2, int col2) {
        if (row1 == row2) return false;
        if (col1 == col2) return false;
        int diff = abs(row1 - row2) - abs(col1 - col2);
        if (diff == 0) return false;
        return true;
    }

    bool compatible(const std::vector<int> &current, int col, int n) {
        int next_row = current.size();
        for (int row = 0; row < current.size(); row++) {
            if (!this->compatible(row, current.at(row), next_row, col)) {
                return false;
            }
        }
        return true;
    }

    void dfs(int &result, std::vector<int> &current, int n) {
        // current stores the column of each queen at row i.
        // base case
        if (current.size() == n) {
            // convert current to correct format
            result += 1;
            return;
        }

        for (int col = 0; col < n; col++) {
            // check compatibility
            if (this->compatible(current, col, n)) {
                current.push_back(col);
                this->dfs(result, current, n);
                current.pop_back();
            }
        }
    }
};
