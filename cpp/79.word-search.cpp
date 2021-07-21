/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (37.55%)
 * Total Accepted:    705.3K
 * Total Submissions: 1.9M
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given an m x n grid of characters board and a string word, return true if
 * word exists in the grid.
 * 
 * The word can be constructed from letters of sequentially adjacent cells,
 * where adjacent cells are horizontally or vertically neighboring. The same
 * letter cell may not be used more than once.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
 * = "ABCCED"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
 * = "SEE"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
 * = "ABCB"
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == board.length
 * n = board[i].length
 * 1 <= m, n <= 6
 * 1 <= word.length <= 15
 * board and word consists of only lowercase and uppercase English letters.
 * 
 * 
 * 
 * Follow up: Could you use search pruning to make your solution faster with a
 * larger board?
 * 
 */

#include "common.hpp"

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        // find all the possible starting position
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (this->helper(board, 0, i, j, visited, word)) return true;
            }   
        }
        return false;
    }

private:
    bool helper(vector<vector<char>>& board, int curr_index, int x, int y, vector<vector<bool>> &visited, string &word) {
        // finishes
        if (curr_index >= word.size()) return true;
        // out of bound
        if (x < 0 || x > board.size() - 1 || y < 0 || y > board[0].size() - 1) return false;
        // visited or not equal
        if (visited[x][y] || word[curr_index] != board[x][y]) return false;
        
        visited[x][y] = true;
        if (this->helper(board, curr_index + 1, x - 1, y, visited, word)) return true;
        if (this->helper(board, curr_index + 1, x + 1, y, visited, word)) return true;
        if (this->helper(board, curr_index + 1, x, y - 1, visited, word)) return true;
        if (this->helper(board, curr_index + 1, x, y + 1, visited, word)) return true;
        visited[x][y] = false;

        return false;
    }
};
