/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 *
 * https://leetcode.com/problems/subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (43.72%)
 * Total Accepted:    493K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,1,1]\n2'
 *
 * Given an array of integers nums and an integer k, return the total number of
 * continuous subarrays whose sum equals to k.
 * 
 * 
 * Example 1:
 * Input: nums = [1,1,1], k = 2
 * Output: 2
 * Example 2:
 * Input: nums = [1,2,3], k = 3
 * Output: 2
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 2 * 10^4
 * -1000 <= nums[i] <= 1000
 * -10^7 <= k <= 10^7
 * 
 * 
 */

#include "common.hpp"

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cumulative_sum = 0;
        int total_num = 0;
        std::unordered_map<int, int> cumulative_sum_freq;
        for (int i = 0; i < nums.size(); i++) {
            cumulative_sum += nums[i];
            if (cumulative_sum == k) {
                total_num += 1;
            }
            int expected_prefix_sum = cumulative_sum - k;
            if (cumulative_sum_freq.find(expected_prefix_sum) != cumulative_sum_freq.end()) {
                total_num += cumulative_sum_freq.at(expected_prefix_sum);
            }
            // add the current cumulative_sum
            if (cumulative_sum_freq.find(cumulative_sum) == cumulative_sum_freq.end()) {
                cumulative_sum_freq[cumulative_sum] = 0;
            }
            cumulative_sum_freq[cumulative_sum] += 1;
        }
        return total_num;
    }
};
