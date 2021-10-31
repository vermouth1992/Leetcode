/*
 * @lc app=leetcode id=698 lang=cpp
 *
 * [698] Partition to K Equal Sum Subsets
 *
 * https://leetcode.com/problems/partition-to-k-equal-sum-subsets/description/
 *
 * algorithms
 * Medium (44.92%)
 * Total Accepted:    130.6K
 * Total Submissions: 290.6K
 * Testcase Example:  '[4,3,2,3,5,2,1]\n4'
 *
 * Given an integer array nums and an integer k, return true if it is possible
 * to divide this array into k non-empty subsets whose sums are all equal.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [4,3,2,3,5,2,1], k = 4
 * Output: true
 * Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3),
 * (2,3) with equal sums.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,2,3,4], k = 3
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= k <= nums.length <= 16
 * 1 <= nums[i] <= 10^4
 * The frequency of each element is in the range [1, 4].
 * 
 * 
 */

#include "common.hpp"

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (auto &num : nums) {
            sum += num;
        }
        if (sum % k != 0) return false;
        int each_sum = sum / k;
        // backtracking
        vector<bool> visited (nums.size(), false);
        return dfs(nums, visited, 0, k, each_sum, 0);
    }

private:
    bool dfs(vector<int> &nums, vector<bool> &visited, int current_sum, int left_k, int each_sum, int start_index) {
        // base case
        if (left_k == 0 && current_sum == 0) return true;
        if (current_sum > each_sum) return false;
        if (current_sum == each_sum) {
            // allow restart if the current sub-sum finishes
            return dfs(nums, visited, 0, left_k - 1, each_sum, 0);
        }

        // iterate nums
        for (int i = start_index; i < nums.size(); i++) {
            if (!visited[i]) {
                // visit nums[i]
                visited[i] = true;
                // only allow searching later items to avoid researching
                bool result = dfs(nums, visited, current_sum + nums[i], left_k, each_sum, start_index + 1);
                if (result) return true; // find it
                // otherwise undo and continue search
                visited[i] = false;
            }
        }
        return false;
    }
};
