/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (37.98%)
 * Total Accepted:    809.5K
 * Total Submissions: 2.1M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in ascending order, find the starting
 * and ending position of a given target value.
 * 
 * If target is not found in the array, return [-1, -1].
 * 
 * You must write an algorithm with O(log n) runtime complexity.
 * 
 * 
 * Example 1:
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * Example 2:
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * Example 3:
 * Input: nums = [], target = 0
 * Output: [-1,-1]
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * nums is a non-decreasing array.
 * -10^9 <= target <= 10^9
 * 
 * 
 */

#include "common.hpp"

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size();
        int mid;
        std::vector<int> result;
        while (start < end) {
            mid = (start + end) / 2;
            if (nums[mid] < target) {
                if (start == mid) break;
                start =  mid;
            } else if (nums[mid] > target) {
                if (end == mid) break;
                end = mid;
            } else {
                // find nums[start] != target and nums[target + 1] == target
                if (nums[start] == target) {
                    result.push_back(start);
                } else {
                    int current_end = mid + 1;
                    int current_mid;
                    while (true) {
                        current_mid = (start + current_end) / 2;
                        if (nums[current_mid] != target) {
                            if (nums[current_mid + 1] == target) {
                                result.push_back(current_mid + 1);
                                break;
                            } else {
                                start = current_mid + 1;
                            }
                        } else {
                            if (current_end == current_mid + 1) {
                                result.push_back(current_mid);
                                break;
                            }
                            current_end = current_mid + 1;
                        }
                    }
                }
                // find end_index
                // find nums[start] != target and nums[target + 1] == target
                if (nums[end - 1] == target) {
                    result.push_back(end - 1);
                } else {
                    int current_start = mid;
                    int current_mid;
                    while (true) {
                        current_mid = (current_start + end) / 2;
                        if (nums[current_mid] == target) {
                            if (nums[current_mid + 1] != target) {
                                result.push_back(current_mid);
                                break;
                            } else {
                                current_start = current_mid + 1;
                            }
                        } else {
                            end = current_mid;
                        }
                    }
                }
                return result;
            }
        }
        // can't find it
        result.push_back(-1);
        result.push_back(-1);
        return result;
    }
};
