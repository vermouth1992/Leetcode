/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (33.15%)
 * Total Accepted:    498.4K
 * Total Submissions: 1.5M
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 * 
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 * 
 * You may assume no duplicate exists in the array.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 * 
 */

#include "common.hpp"

class Solution {
private:
    // from [start, end)
    int searchHelper(vector<int>& nums, size_t start, size_t end, int target) {
        if (end - start <= 1) {
            if (nums[start] == target) return start;
            else return -1;
        }
        int mid = (start + end) / 2;
        // [start, mid)
        if (start == mid - 1) {
            if (nums[start] == target) return start;
            return searchHelper(nums, mid, end, target);
        } else if (mid == end - 1) {
            if (nums[mid] == target) return mid;
            else searchHelper(nums, start, mid, target);
        }


        if (nums[start] < nums[mid - 1]) {
            if (target >= nums[start] && target <= nums[mid - 1]) {
                return searchHelper(nums, start, mid, target);
            } else {
                return searchHelper(nums, mid, end, target);
            }
        } else {
            if (target >= nums[mid] && target <= nums[end - 1]) {
                return searchHelper(nums, mid, end, target);
            } else {
                return searchHelper(nums, start, mid, target);
            }
        }

    }

public:
    int search(vector<int>& nums, int target) {
        if (nums.size() <= 0) return -1;
        else return searchHelper(nums, 0, nums.size(), target);
    }
};
