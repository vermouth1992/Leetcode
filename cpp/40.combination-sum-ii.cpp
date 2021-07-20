/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (50.75%)
 * Total Accepted:    431.8K
 * Total Submissions: 844K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sum to target.
 * 
 * Each number in candidates may only be used once in the combination.
 * 
 * Note: The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [10,1,2,7,6,1,5], target = 8
 * Output: 
 * [
 * [1,1,6],
 * [1,2,5],
 * [1,7],
 * [2,6]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,5,2,1,2], target = 5
 * Output: 
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= candidates.length <= 100
 * 1 <= candidates[i] <= 50
 * 1 <= target <= 30
 * 
 * 
 */

#include "common.hpp"

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> curr;
        this->helper(result, curr, candidates, target, 0);
        return result;
    }

private:
    void helper(vector<vector<int>> &result, vector<int> &curr, vector<int>& candidates, int target, int startIndex) {
        if (target == 0) {
            result.push_back(vector(curr));
            return;
        }

        for (int i = startIndex; i < candidates.size(); i++) {
            if (candidates[i] > target) break;
            // remove duplicate by not including different variants of the same number once the number is in the curr.
            if (i > startIndex && candidates[i] == candidates[i - 1]) continue;
            curr.push_back(candidates[i]);
            this->helper(result, curr, candidates, target - candidates[i], i + 1);
            curr.pop_back();
        }
    }
};
