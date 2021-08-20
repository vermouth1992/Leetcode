/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 *
 * https://leetcode.com/problems/minimum-falling-path-sum/description/
 *
 * algorithms
 * Medium (64.16%)
 * Total Accepted:    83.9K
 * Total Submissions: 129.1K
 * Testcase Example:  '[[2,1,3],[6,5,4],[7,8,9]]'
 *
 * Given an n x n array of integers matrix, return the minimum sum of any
 * falling path through matrix.
 * 
 * A falling path starts at any element in the first row and chooses the
 * element in the next row that is either directly below or diagonally
 * left/right. Specifically, the next element from position (row, col) will be
 * (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
 * Output: 13
 * Explanation: There are two falling paths with a minimum sum underlined
 * below:
 * [[2,1,3],      [[2,1,3],
 * ⁠[6,5,4],       [6,5,4],
 * ⁠[7,8,9]]       [7,8,9]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = [[-19,57],[-40,-5]]
 * Output: -59
 * Explanation: The falling path with a minimum sum is underlined below:
 * [[-19,57],
 * ⁠[-40,-5]]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: matrix = [[-48]]
 * Output: -48
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == matrix.length
 * n == matrix[i].length
 * 1 <= n <= 100
 * -100 <= matrix[i][j] <= 100
 * 
 * 
 */

#include "common.hpp"

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp (n, vector<int> (n, 0));
        // initialize last row
        for (int i = 0; i < n; i++) {
            dp.at(n - 1).at(i) = matrix.at(n - 1).at(i);
        }
        // bottom up
        for (int row = n - 2; row >= 0; row--) {
            for (int col = 0; col < n; col++) {
                int min_val = dp.at(row + 1).at(col);
                if (col != 0 && min_val > dp.at(row + 1).at(col - 1)) {
                    // left one
                    min_val = dp.at(row + 1).at(col - 1);
                }
                if (col != n - 1 && min_val > dp.at(row + 1).at(col + 1)) {
                    // right one
                    min_val = dp.at(row + 1).at(col + 1);
                }

                dp.at(row).at(col) = min_val + matrix.at(row).at(col);
            }
        }
        return *std::min_element(dp.at(0).begin(), dp.at(0).end());
    }
};


int main() {
    vector<vector<int>> a = {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
    std::cout << Solution().minFallingPathSum(a);
    return 0;
}