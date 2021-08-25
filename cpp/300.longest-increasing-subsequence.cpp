/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 *
 * https://leetcode.com/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (45.01%)
 * Total Accepted:    635.1K
 * Total Submissions: 1.4M
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * Given an integer array nums, return the length of the longest strictly
 * increasing subsequence.
 * 
 * A subsequence is a sequence that can be derived from an array by deleting
 * some or no elements without changing the order of the remaining elements.
 * For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [10,9,2,5,3,7,101,18]
 * Output: 4
 * Explanation: The longest increasing subsequence is [2,3,7,101], therefore
 * the length is 4.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [0,1,0,3,2,3]
 * Output: 4
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [7,7,7,7,7,7,7]
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 2500
 * -10^4 <= nums[i] <= 10^4
 * 
 * 
 * 
 * Follow up: Can you come up with an algorithm that runs in O(n log(n)) time
 * complexity?
 * 
 */

#include "common.hpp"

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> curr {nums[0]};  // nums.length >= 1
        for (int i = 1; i < nums.size(); i++) {
            // maximum element
            if (nums[i] > curr.back()) {
                curr.push_back(nums[i]);
            } else if (nums[i] < curr[0]) {
                curr.at(0) = nums[i];
            } else {
                // replace the element in the curr with sorted order
                int start = 0;
                int end = curr.size() - 1;
                int mid;
                while (start < end) {
                    mid = (start + end) / 2;
                    if (nums[i] > curr[mid]) {
                        start = mid + 1;
                    } else if (nums[i] < curr[mid]) {
                        end = mid;
                    } else {
                        // no replace is needed
                        start = mid;
                        break;
                    }
                }
                curr[start] = nums[i];
            }
        }
        return curr.size();
    }
};