/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations/description/
 *
 * algorithms
 * Medium (58.59%)
 * Total Accepted:    386.1K
 * Total Submissions: 651.1K
 * Testcase Example:  '4\n2'
 *
 * Given two integers n and k, return all possible combinations of k numbers
 * out of the range [1, n].
 * 
 * You may return the answer in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 4, k = 2
 * Output:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 1, k = 1
 * Output: [[1]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 20
 * 1 <= k <= n
 * 
 * 
 */

#include "common.hpp"

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> curr;
        this->helper(result, curr, 1, k, n);
        return result;
    }

private:
    void helper(vector<vector<int>> &result, vector<int> &curr, int start, int leftNum, int n) {
        if (leftNum == 0) {
            result.push_back(vector(curr));
            return;
        }

        for (int i = start; i <= n; i++) {
            curr.push_back(i);
            this->helper(result, curr, i + 1, leftNum - 1, n);
            curr.pop_back();
        }
    }
};
