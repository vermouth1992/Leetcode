/*
 * @lc app=leetcode id=915 lang=cpp
 *
 * [915] Partition Array into Disjoint Intervals
 *
 * https://leetcode.com/problems/partition-array-into-disjoint-intervals/description/
 *
 * algorithms
 * Medium (46.77%)
 * Total Accepted:    45.7K
 * Total Submissions: 95.6K
 * Testcase Example:  '[5,0,3,8,6]'
 *
 * Given an array nums, partition it into two (contiguous) subarrays left and
 * right so that:
 * 
 * 
 * Every element in left is less than or equal to every element in right.
 * left and right are non-empty.
 * left has the smallest possible size.
 * 
 * 
 * Return the length of left after such a partitioning.  It is guaranteed that
 * such a partitioning exists.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [5,0,3,8,6]
 * Output: 3
 * Explanation: left = [5,0,3], right = [8,6]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,1,1,0,6,12]
 * Output: 4
 * Explanation: left = [1,1,1,0], right = [6,12]
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 2 <= nums.length <= 30000
 * 0 <= nums[i] <= 10^6
 * It is guaranteed there is at least one way to partition nums as
 * described.
 * 
 * 
 * 
 * 
 * 
 * 
 */

#include "common.hpp"

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int i;
        for (i = nums.size() - 1; i > 0; i--)
        {
            if (nums[i] < nums[0]) break;
        }
        // find the maximum from 0 to i;
        int max = nums[0];
        for (size_t j = 1; j < i + 1; j++)
        {
            if (nums[j] > max) max = nums[j];
        }
        for (i = nums.size() - 1; i > 0; i--)
        {
            if (nums[i] < max) break;
        }
        return i + 1;
    }
};
