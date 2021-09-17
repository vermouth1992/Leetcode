/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 *
 * https://leetcode.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (51.89%)
 * Total Accepted:    300.7K
 * Total Submissions: 557.3K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n x n
 * chessboard such that no two queens attack each other.
 * 
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * You may return the answer in any order.
 * 
 * Each solution contains a distinct board configuration of the n-queens'
 * placement, where 'Q' and '.' both indicate a queen and an empty space,
 * respectively.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 4
 * Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
 * Explanation: There exist two distinct solutions to the 4-queens puzzle as
 * shown above
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 1
 * Output: [["Q"]]
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
    vector<vector<string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> result;
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

    std::vector<std::string> convert(const std::vector<int> &current, int n) {
        std::vector<std::string> result;
        for (auto &col : current) {
            std::string s(n, '.');
            s.at(col) = 'Q';
            result.push_back(s);
        }
        return result;
    }

    void dfs(std::vector<std::vector<std::string>> &result, std::vector<int> &current, int n) {
        // current stores the column of each queen at row i.
        // base case
        if (current.size() == n) {
            // convert current to correct format
            result.push_back(this->convert(current, n));
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
