/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 *
 * https://leetcode.com/problems/combination-sum-iii/description/
 *
 * algorithms
 * Medium (61.07%)
 * Total Accepted:    240.3K
 * Total Submissions: 389.5K
 * Testcase Example:  '3\n7'
 *
 * Find all valid combinations of k numbers that sum up to n such that the
 * following conditions are true:
 * 
 * 
 * Only numbers 1 through 9 are used.
 * Each number is used at most once.
 * 
 * 
 * Return a list of all possible valid combinations. The list must not contain
 * the same combination twice, and the combinations may be returned in any
 * order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: k = 3, n = 7
 * Output: [[1,2,4]]
 * Explanation:
 * 1 + 2 + 4 = 7
 * There are no other valid combinations.
 * 
 * Example 2:
 * 
 * 
 * Input: k = 3, n = 9
 * Output: [[1,2,6],[1,3,5],[2,3,4]]
 * Explanation:
 * 1 + 2 + 6 = 9
 * 1 + 3 + 5 = 9
 * 2 + 3 + 4 = 9
 * There are no other valid combinations.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: k = 4, n = 1
 * Output: []
 * Explanation: There are no valid combinations.
 * Using 4 different numbers in the range [1,9], the smallest sum we can get is
 * 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: k = 3, n = 2
 * Output: []
 * Explanation: There are no valid combinations.
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: k = 9, n = 45
 * Output: [[1,2,3,4,5,6,7,8,9]]
 * Explanation:
 * 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 = 45
 * There are no other valid combinations.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= k <= 9
 * 1 <= n <= 60
 * 
 * 
 */

#include "common.hpp"

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> curr;
        vector<bool> used (9, false);
        this->helper(result, curr, used, k, n, 1);
        return result;
    }

private:
    void helper(vector<vector<int>> &result, vector<int> &curr, vector<bool> &used, int k, int n, int start) {
        // n is the left sum.
        if (n < 0) return;
        if (n == 0 && curr.size() < k) return;
        if (curr.size() == k) {
            if (n == 0) {
                result.push_back(vector(curr));
            }
            return;
        }
        for (int i = start; i <= 9; i++) {
            if (!used[i - 1]) {
                curr.push_back(i);
                used[i - 1] = true;
                this->helper(result, curr, used, k, n - i, i + 1);
                used[i - 1] = false;
                curr.pop_back();
            }
        }
    }
};
