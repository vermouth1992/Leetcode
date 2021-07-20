/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (66.25%)
 * Total Accepted:    812.2K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,3]'
 *
 * Given an integer array nums of unique elements, return all possible subsets
 * (the power set).
 * 
 * The solution set must not contain duplicate subsets. Return the solution in
 * any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [0]
 * Output: [[],[0]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10
 * -10 <= nums[i] <= 10
 * All the numbers of nums are unique.
 * 
 * 
 */

#include "common.hpp"

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        for (size_t k = 0; k <= nums.size(); k++)
        {
            vector<int> curr;
            this->helper(result, curr, 0, k, nums);
        }
        return result;
    }

private:
    void helper(vector<vector<int>> &result, vector<int> &curr, int start, int leftNum, vector<int> &nums) {
        if (leftNum == 0) {
            result.push_back(vector(curr));
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            this->helper(result, curr, i + 1, leftNum - 1, nums);
            curr.pop_back();
        }
    }

};
