/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (48.04%)
 * Total Accepted:    1.6M
 * Total Submissions: 3.3M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 * 
 * A subarray is a contiguous part of an array.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1]
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [5,4,-1,7,8]
 * Output: 23
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 3 * 10^4
 * -10^5 <= nums[i] <= 10^5
 * 
 * 
 * 
 * Follow up: If you have figured out the O(n) solution, try coding another
 * solution using the divide and conquer approach, which is more subtle.
 * 
 */

#include "common.hpp"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // sum[i, j] = cumulative_sum[j] - cumulative_sum[i - 1]
        // The problem becomes bell stock problem
        vector<int> cumulative_sum(nums.size(), 0);
        int s = 0;
        // O(N)
        for (int i = 0; i < nums.size(); i++) {
            s += nums[i];
            cumulative_sum[i] = s;
        }
        int minimum = 0;  // valid
        int max_sum = cumulative_sum[0];
        // This can be optimized. The cumulative sum can be computed online
        for (int i = 0; i < cumulative_sum.size(); i++) {
            int current_max_sum = cumulative_sum[i] - minimum;
            if (current_max_sum > max_sum) {
                max_sum = current_max_sum;
            }
            if (cumulative_sum[i] < minimum) {
                minimum = cumulative_sum[i];
            }
        }
        return max_sum;
    }
};
