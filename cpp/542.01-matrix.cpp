/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 *
 * https://leetcode.com/problems/01-matrix/description/
 *
 * algorithms
 * Medium (41.40%)
 * Total Accepted:    151.1K
 * Total Submissions: 355.7K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * Given an m x n binary matrix mat, return the distance of the nearest 0 for
 * each cell.
 * 
 * The distance between two adjacent cells is 1.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
 * Output: [[0,0,0],[0,1,0],[0,0,0]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
 * Output: [[0,0,0],[0,1,0],[1,2,1]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == mat.length
 * n == mat[i].length
 * 1 <= m, n <= 10^4
 * 1 <= m * n <= 10^4
 * mat[i][j] is either 0 or 1.
 * There is at least one 0 in mat.
 * 
 * 
 */

#include "common.hpp"

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // find all the zeros and set to zero. perform BFS search of all the nodes
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> result(m, vector<int>(n, 0));
        vector<vector<bool>> explored(m, vector<bool>(n, false));
        queue<pair<int, int>> frontier;
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                if (mat.at(i).at(j) == 0) {
                    auto pair = std::make_pair(i, j);
                    explored.at(i).at(j) = true;
                    frontier.push(pair);
                }
            }
        }
        int current_d = 1;
        while (!frontier.empty()) {
            int current_size = frontier.size();
            for (int i = 0; i < current_size; i++) {
                auto top = frontier.front();
                frontier.pop();
                // left
                if (top.first >= 1) {
                    auto curr = std::make_pair(top.first - 1, top.second);
                    // haven't been explored
                    if (!explored.at(curr.first).at(curr.second)) {
                        frontier.push(curr);
                        explored.at(curr.first).at(curr.second) = true;
                        result.at(curr.first).at(curr.second) = current_d;
                    }
                }
                // right
                if (top.first < m - 1) {
                    auto curr = std::make_pair(top.first + 1, top.second);
                    // haven't been explored
                    if (!explored.at(curr.first).at(curr.second)) {
                        frontier.push(curr);
                        explored.at(curr.first).at(curr.second) = true;
                        result.at(curr.first).at(curr.second) = current_d;
                    }
                }
                // left
                if (top.second >= 1) {
                    auto curr = std::make_pair(top.first, top.second - 1);
                    // haven't been explored
                    if (!explored.at(curr.first).at(curr.second)) {
                        frontier.push(curr);
                        explored.at(curr.first).at(curr.second) = true;
                        result.at(curr.first).at(curr.second) = current_d;
                    }
                }
                // right
                if (top.second < n - 1) {
                    auto curr = std::make_pair(top.first, top.second + 1);
                    // haven't been explored
                    if (!explored.at(curr.first).at(curr.second)) {
                        frontier.push(curr);
                        explored.at(curr.first).at(curr.second) = true;
                        result.at(curr.first).at(curr.second) = current_d;
                    }
                }
            }   
            current_d += 1;
        }
        return result;
    }
};


int main() {
    vector<vector<int>> a {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    Solution().updateMatrix(vector());
    return 0;
}