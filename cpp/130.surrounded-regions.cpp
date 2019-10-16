/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 *
 * https://leetcode.com/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (23.93%)
 * Total Accepted:    166.6K
 * Total Submissions: 686.7K
 * Testcase Example:  '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
 *
 * Given a 2D board containing 'X' and 'O' (the letter O), capture all regions
 * surrounded by 'X'.
 * 
 * A region is captured by flipping all 'O's into 'X's in that surrounded
 * region.
 * 
 * Example:
 * 
 * 
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 * 
 * 
 * After running your function, the board should be:
 * 
 * 
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 * 
 * 
 * Explanation:
 * 
 * Surrounded regions shouldn’t be on the border, which means that any 'O' on
 * the border of the board are not flipped to 'X'. Any 'O' that is not on the
 * border and it is not connected to an 'O' on the border will be flipped to
 * 'X'. Two cells are connected if they are adjacent cells connected
 * horizontally or vertically.
 * 
 */

#include "common.hpp"

class Solution {
    typedef std::pair<int, int> Position;
private:
    void bfs(vector<vector<char>> &board, set<Position> &remainingPos, Position startPosition) {
        // perform bfs from startPosition and record all traversed position.
        // If any of them is on the boarder, flip all positions 
        queue<Position> frontier;
        frontier.push(startPosition);
        set<Position> explored;   // set of positions in the island with startPosition
        bool hasBoarder = false;
        while (!frontier.empty())
        {
            auto currentPos = frontier.front();
            frontier.pop();
            if (remainingPos.find(currentPos) == remainingPos.end()) continue;
            
            remainingPos.erase(currentPos);
            explored.insert(currentPos);
            if (!hasBoarder) {
                if (currentPos.first == 0 || currentPos.first == board.size() - 1 || currentPos.second == 0 || 
                        currentPos.second == board[0].size() - 1) {
                    hasBoarder = true;
                }
            }
            
            std::set<Position> possibleNext;
            possibleNext.insert(std::make_pair(currentPos.first - 1, currentPos.second));
            possibleNext.insert(std::make_pair(currentPos.first + 1, currentPos.second));
            possibleNext.insert(std::make_pair(currentPos.first, currentPos.second + 1));
            possibleNext.insert(std::make_pair(currentPos.first, currentPos.second - 1));
            for (auto &pos : possibleNext) {
                if (pos.first >= 0 && pos.first < board.size() && pos.second >= 0 && pos.second < board[0].size()) {
                    if (board[pos.first][pos.second] == 'O') {
                        if (remainingPos.find(pos) != remainingPos.end()) {
                            frontier.push(pos);
                        }
                    }
                }
            }
        }
        if (!hasBoarder) {
            for (auto &pos : explored) {
                board[pos.first][pos.second] = 'X';
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        if (board.size() <= 0) return;
        if (board[0].size() <= 0) return;
        std::set<Position> remainingLandsPos;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == 'O') {
                    remainingLandsPos.insert(std::make_pair(i, j));
                }
            }
        }

        while (!remainingLandsPos.empty())
        {
            auto startingPos = *remainingLandsPos.begin();
            bfs(board, remainingLandsPos, startingPos);
        }
    }
};
