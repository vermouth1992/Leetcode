/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (24.73%)
 * Total Accepted:    642.3K
 * Total Submissions: 2.6M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */

#include "common.hpp"

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() < 3) return result;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i != 0 && nums[i] == nums[i - 1]) continue;
            int start = i + 1;
            int end = nums.size() - 1;
            int current_sum = -nums[i];
            while (start < end) {
                if (nums[start] + nums[end] < current_sum) {
                    start += 1;
                } else if (nums[start] + nums[end] > current_sum) {
                    end -= 1;
                } else {
                    result.push_back(std::vector<int> {nums[i], nums[start], nums[end]});
                    // find the next start and end not equal to the current one
                    start += 1;
                    end -= 1;
                    while (start < end && nums[start] == nums[start - 1]) {
                        start += 1;
                    }
                    while (start < end && nums[end] == nums[end + 1]) {
                        end -= 1;
                    }
                }
            }
        }
        return result;
    }
};