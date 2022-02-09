/*
 * @lc app=leetcode id=532 lang=cpp
 *
 * [532] K-diff Pairs in an Array
 *
 * https://leetcode.com/problems/k-diff-pairs-in-an-array/description/
 *
 * algorithms
 * Medium (35.83%)
 * Total Accepted:    199.9K
 * Total Submissions: 531.3K
 * Testcase Example:  '[3,1,4,1,5]\n2'
 *
 * Given an array of integers nums and an integer k, return the number of
 * unique k-diff pairs in the array.
 * 
 * A k-diff pair is an integer pair (nums[i], nums[j]), where the following are
 * true:
 * 
 * 
 * 0 <= i < j < nums.length
 * |nums[i] - nums[j]| == k
 * 
 * 
 * Notice that |val| denotes the absolute value of val.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [3,1,4,1,5], k = 2
 * Output: 2
 * Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
 * Although we have two 1s in the input, we should only return the number of
 * unique pairs.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,2,3,4,5], k = 1
 * Output: 4
 * Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3,
 * 4) and (4, 5).
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1,3,1,5,4], k = 0
 * Output: 1
 * Explanation: There is one 0-diff pair in the array, (1, 1).
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^4
 * -10^7 <= nums[i] <= 10^7
 * 0 <= k <= 10^7
 * 
 * 
 */

#include "common.hpp"

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        std::unordered_set<int> positive_residual; // the residual is greater than the number
        std::unordered_set<int> negative_residual; // the residual is smaller than the number
        std::unordered_set<int> positive_explored;
        std::unordered_set<int> negative_explored;
        int result = 0;
        for (auto &num: nums) {
            bool find_in_positive;
            bool find_in_negative;
            if (positive_residual.find(num) != positive_residual.end()) {
                find_in_positive = true;
                if (positive_explored.find(num) == positive_explored.end()) {
                    result += 1;
                    positive_explored.insert(num);
                }
            } else {
                find_in_positive = false;
            }
            if (k != 0) {
                if (negative_residual.find(num) != negative_residual.end()) {
                    find_in_negative = true;
                    if (negative_explored.find(num) == negative_explored.end()) {
                        result += 1;
                        negative_explored.insert(num);
                    }
                } else {
                    find_in_negative = false;
                }
            }
            
            if (!find_in_negative) {
                positive_residual.insert(num + k);
            }
            
            if (k != 0 && !find_in_positive) {
                negative_residual.insert(num - k);
            }
            
        }
        return result;
    }
};
