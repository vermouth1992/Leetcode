/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (67.67%)
 * Total Accepted:    866.4K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,2,3]'
 *
 * Given an array nums of distinct integers, return all the possible
 * permutations. You can return the answer in any order.
 * 
 * 
 * Example 1:
 * Input: nums = [1,2,3]
 * Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * Example 2:
 * Input: nums = [0,1]
 * Output: [[0,1],[1,0]]
 * Example 3:
 * Input: nums = [1]
 * Output: [[1]]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 6
 * -10 <= nums[i] <= 10
 * All the integers of nums are unique.
 * 
 * 
 */

#include "common.hpp"

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        vector<bool> visited(nums.size(), false);
        this->helper(result, curr, nums, visited);
        return result;
    }

private:
    void helper(vector<vector<int>> &result, vector<int> &curr, vector<int>& nums, vector<bool>& visited) {
        if (curr.size() == nums.size()) {
            result.push_back(vector(curr));
            return;
        }

        for (size_t i = 0; i < nums.size(); i++)
        {
            if (visited[i]) continue;
            curr.push_back(nums[i]);
            visited[i] = true;
            this->helper(result, curr, nums, visited);
            curr.pop_back();
            visited[i] = false;
        }
    }
};
