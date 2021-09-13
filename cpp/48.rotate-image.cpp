/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 *
 * https://leetcode.com/problems/rotate-image/description/
 *
 * algorithms
 * Medium (61.62%)
 * Total Accepted:    676.4K
 * Total Submissions: 1.1M
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * You are given an n x n 2D matrix representing an image, rotate the image by
 * 90 degrees (clockwise).
 * 
 * You have to rotate the image in-place, which means you have to modify the
 * input 2D matrix directly. DO NOT allocate another 2D matrix and do the
 * rotation.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * Output: [[7,4,1],[8,5,2],[9,6,3]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
 * Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: matrix = [[1]]
 * Output: [[1]]
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: matrix = [[1,2],[3,4]]
 * Output: [[3,1],[4,2]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * matrix.length == n
 * matrix[i].length == n
 * 1 <= n <= 20
 * -1000 <= matrix[i][j] <= 1000
 * 
 * 
 */

#include "common.hpp"

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // swap every four elements
        int n = matrix.size();
        int half_n = n / 2;
        for (int row = 0; row < half_n; row++) {
            // for each row, select the 
            for (int col = row; col < n - row - 1; col++) {
                // std::cout << row << " " << col << std::endl;
                // find the four position
                std::vector<std::pair<int, int>> pos;
                pos.push_back(std::make_pair(row, col));
                pos.push_back(std::make_pair(col, n - 1 - row));
                pos.push_back(std::make_pair(n - 1 - row, n - 1 - col));
                pos.push_back(std::make_pair(n - 1 - col, row));
                this->rotate_pos(matrix, pos);
            }
        }
    }

    void print_matrix(std::vector<std::vector<int>> &matrix) {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.size(); j++) {
                std::cout << matrix.at(i).at(j) << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

private:
    int& get_val(std::vector<std::vector<int>> &matrix, std::pair<int, int> &p) const {
        return matrix.at(p.first).at(p.second);
    }

    void rotate_pos(std::vector<std::vector<int>> &matrix, std::vector<std::pair<int, int>> &pos) {
        // rotate the value of matrix in the position. 0 -> 1, 1 -> 2, 2 -> 3, 3 -> 0 etc
        int last_val = get_val(matrix, pos.at(3));
        for (int i = 3; i >= 1; i--) {
            get_val(matrix, pos.at(i)) = get_val(matrix, pos.at(i - 1));
            // print_matrix(matrix);
        }
        get_val(matrix, pos.at(0)) = last_val;
    }
};


int main() {
    std::vector<std::vector<int>> matrix {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    Solution().rotate(matrix);

    Solution().print_matrix(matrix);

    return 0;
}