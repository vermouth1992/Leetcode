/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 *
 * https://leetcode.com/problems/sudoku-solver/description/
 *
 * algorithms
 * Hard (47.81%)
 * Total Accepted:    284.5K
 * Total Submissions: 560.1K
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 * 
 * A sudoku solution must satisfy all of the following rules:
 * 
 * 
 * Each of the digits 1-9 must occur exactly once in each row.
 * Each of the digits 1-9 must occur exactly once in each column.
 * Each of the digits 1-9 must occur exactly once in each of the 9 3x3
 * sub-boxes of the grid.
 * 
 * 
 * The '.' character indicates empty cells.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: board =
 * [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
 * Output:
 * [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
 * Explanation: The input board is shown above and the only valid solution is
 * shown below:
 * 
 * 
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * board.length == 9
 * board[i].length == 9
 * board[i][j] is a digit or '.'.
 * It is guaranteed that the input board has only one solution.
 * 
 * 
 */

#include "common.hpp"

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        // find all the empty position
        std::vector<std::pair<int, int>> empty;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.at(0).size(); j++) {
                auto current_pos = std::make_pair(i, j);
                if (get_board_char(board, current_pos) == empty_char) {
                    empty.push_back(current_pos);
                }
            }
        }
        this->dfs(board, empty, 0);
    }


private:
    const char empty_char = '.';

    std::vector<char> get_possible_values(std::vector<std::vector<char>>&board, const std::pair<int, int> &pos) {
        std::vector<bool> availability(9, true);
        int row = pos.first;
        int col = pos.second;
        // look at the current row
        for (auto &c : board.at(row)) {
            if (c != empty_char) {
                availability.at(c - '1') = false;
            }
        }
        // look at the current column
        for (int r = 0; r < board.size(); r++) {
            auto c = board.at(r).at(col);
            if (c != empty_char) {
                availability.at(c - '1') = false;
            }
        }
        // look at the 3x3 sub-boxes
        int row_blk_idx = row / 3;
        int col_blk_idx = col / 3;
        int row_blk_start_idx = row_blk_idx * 3;
        int col_blk_start_idx = col_blk_idx * 3;
        for (int row_offset = 0; row_offset < 3; row_offset++) {
            for (int col_offset = 0; col_offset < 3; col_offset++) {
                auto c = board.at(row_offset + row_blk_start_idx).at(col_offset + col_blk_start_idx);
                if (c != empty_char) {
                    availability.at(c - '1') = false;
                }
            }
        }
        // add left true
        std::vector<char> result;
        for (int i = 0; i < availability.size(); i++) {
            if (availability.at(i)) {
                result.push_back('1' + i);
            }
        }
        return result;
    }

    char & get_board_char(std::vector<std::vector<char>>&board, const std::pair<int, int> &pos) {
        // return a reference so that it can be directly modified
        return board.at(pos.first).at(pos.second);
    }

    bool dfs(std::vector<std::vector<char>>&board, const std::vector<std::pair<int, int>> &empty, int current_idx) {
        // find the possible value for the current_idx
        if (current_idx == empty.size()) return true;
        auto current_pos = empty.at(current_idx);
        std::vector<char> possible_value = this->get_possible_values(board, current_pos);
        for (auto &val : possible_value) {
            get_board_char(board, current_pos) = val;
            bool result = this->dfs(board, empty, current_idx + 1);
            if (result) return true;
        }
        // nothing works. reset the character and return false
        get_board_char(board, current_pos) = empty_char;
        return false;
    }
};
