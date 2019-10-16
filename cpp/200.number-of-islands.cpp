/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (42.78%)
 * Total Accepted:    446.9K
 * Total Submissions: 1M
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of
 * islands. An island is surrounded by water and is formed by connecting
 * adjacent lands horizontally or vertically. You may assume all four edges of
 * the grid are all surrounded by water.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * 11110
 * 11010
 * 11000
 * 00000
 * 
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * 11000
 * 11000
 * 00100
 * 00011
 * 
 * Output: 3
 * 
 */

#include "common.hpp"

class Solution {
    typedef std::pair<int, int> Position;
private:
    void bfs(vector<vector<char>> &grid, set<Position> &remainingLandsPos, Position &startPosition) {
        // from starting position, perform bfs and remove all traversed position from remainingLands
        queue<Position> frontier;
        frontier.push(startPosition);
        while (!frontier.empty())
        {
            auto currentPos = frontier.front();
            frontier.pop();
            if (remainingLandsPos.find(currentPos) == remainingLandsPos.end()) continue;
            remainingLandsPos.erase(currentPos);
            std::set<Position> possibleNext;
            possibleNext.insert(std::make_pair(currentPos.first - 1, currentPos.second));
            possibleNext.insert(std::make_pair(currentPos.first + 1, currentPos.second));
            possibleNext.insert(std::make_pair(currentPos.first, currentPos.second + 1));
            possibleNext.insert(std::make_pair(currentPos.first, currentPos.second - 1));
            for (auto &pos : possibleNext) {
                if (pos.first >= 0 && pos.first < grid.size() && pos.second >= 0 && pos.second < grid[0].size()) {
                    if (grid[pos.first][pos.second] == '1') {
                        if (remainingLandsPos.find(pos) != remainingLandsPos.end()) {
                            frontier.push(pos);
                        }
                    }
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() <= 0) return 0;
        if (grid[0].size() <= 0) return 0;
        std::set<Position> remainingLandsPos;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1') {
                    remainingLandsPos.insert(std::make_pair(i, j));
                }
            }
        }
        int num = 0;
        while (!remainingLandsPos.empty())
        {
            auto startingPos = *remainingLandsPos.begin();
            bfs(grid, remainingLandsPos, startingPos);
            num += 1;
        }
        return num;
    }
};
