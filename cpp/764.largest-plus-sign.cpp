/*
 * @lc app=leetcode id=764 lang=cpp
 *
 * [764] Largest Plus Sign
 *
 * https://leetcode.com/problems/largest-plus-sign/description/
 *
 * algorithms
 * Medium (46.89%)
 * Total Accepted:    37.9K
 * Total Submissions: 78.5K
 * Testcase Example:  '5\n[[4,2]]'
 *
 * You are given an integer n. You have an n x n binary grid grid with all
 * values initially 1's except for some indices given in the array mines. The
 * i^th element of the array mines is defined as mines[i] = [xi, yi] where
 * grid[xi][yi] == 0.
 * 
 * Return the order of the largest axis-aligned plus sign of 1's contained in
 * grid. If there is none, return 0.
 * 
 * An axis-aligned plus sign of 1's of order k has some center grid[r][c] == 1
 * along with four arms of length k - 1 going up, down, left, and right, and
 * made of 1's. Note that there could be 0's or 1's beyond the arms of the plus
 * sign, only the relevant area of the plus sign is checked for 1's.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 5, mines = [[4,2]]
 * Output: 2
 * Explanation: In the above grid, the largest plus sign can only be of order
 * 2. One of them is shown.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 1, mines = [[0,0]]
 * Output: 0
 * Explanation: There is no plus sign, so return 0.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 500
 * 1 <= mines.length <= 5000
 * 0 <= xi, yi < n
 * All the pairs (xi, yi) are unique.
 * 
 * 
 */

#include "common.hpp"

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        // sort the mines in row and column fashion. Fill in the number between two zeros in a row fashion
        // then fill in the number between two zeros in a column fashion. Return the maximum number in the table
        std::vector<std::vector<int>> dp (n, std::vector<int> (n, 0));
        std::vector<std::vector<int>> column_zero_idx (n, std::vector<int> {-1, n});
        std::vector<std::vector<int>> row_zero_idx (n, std::vector<int> {-1, n});
        // for each row, construct a sorted column with zeros.
        for (auto& pos : mines) {
            int row = pos.at(0);
            int col = pos.at(1);
            column_zero_idx.at(row).push_back(col);
            row_zero_idx.at(col).push_back(row);
        }

        for (auto& row : column_zero_idx) {
            // this can be optimized
            std::sort(row.begin(), row.end());
        }
        for (auto& col : row_zero_idx) {
            std::sort(col.begin(), col.end());
        }
        
        // for each row, fill the dp values between two consecutive zeros. 
        for (int row = 0; row < n; row++) {
            for (int i = 0; i < column_zero_idx.at(row).size() - 1; i++) {
                int col1 = column_zero_idx.at(row).at(i) + 1;
                int col2 = column_zero_idx.at(row).at(i + 1) - 1;
                // fill in the between
                int current = 1;
                while (col1 <= col2) {
                    // std::cout << "Here" << col1 << " " << col2 << std::endl;
                    dp.at(row).at(col1) = current;
                    dp.at(row).at(col2) = current;
                    col1 += 1;
                    col2 -= 1;
                    current += 1;
                }
            }
        }

        int maximum = 0;
        // for each column, fill the dp values between two consecutive zeros, choose the minimum one. also keep track of the maximum
        for (int col = 0; col < n; col++) {
            for (int i = 0; i < row_zero_idx.at(col).size() - 1; i++) {
                int row1 = row_zero_idx.at(col).at(i) + 1;
                int row2 = row_zero_idx.at(col).at(i + 1) - 1;
                // fill in the between
                int current = 1;
                while (row1 <= row2) {
                    dp.at(row1).at(col) = std::min(current, dp.at(row1).at(col));
                    dp.at(row2).at(col) = std::min(current, dp.at(row2).at(col));
                    maximum = std::max(maximum, dp.at(row1).at(col));
                    maximum = std::max(maximum, dp.at(row2).at(col));
                    row1 += 1;
                    row2 -= 1;
                    current += 1;
                }
            }
        }
        return maximum;
    }
};


int main() {
    std::vector<std::vector<int>> a {{4, 2}};
    std::cout << Solution().orderOfLargestPlusSign(5, a) << std::endl;
    return 0;
}