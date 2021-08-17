/*
 * @lc app=leetcode id=1818 lang=cpp
 *
 * [1818] Minimum Absolute Sum Difference
 *
 * https://leetcode.com/problems/minimum-absolute-sum-difference/description/
 *
 * algorithms
 * Medium (40.23%)
 * Total Accepted:    9.4K
 * Total Submissions: 33.1K
 * Testcase Example:  '[1,7,5]\n[2,3,5]'
 *
 * You are given two positive integer arrays nums1 and nums2, both of length
 * n.
 * 
 * The absolute sum difference of arrays nums1 and nums2 is defined as the sum
 * of |nums1[i] - nums2[i]| for each 0 <= i < n (0-indexed).
 * 
 * You can replace at most one element of nums1 with any other element in nums1
 * to minimize the absolute sum difference.
 * 
 * Return the minimum absolute sum difference after replacing at most one
 * element in the array nums1. Since the answer may be large, return it modulo
 * 10^9 + 7.
 * 
 * |x| is defined as:
 * 
 * 
 * x if x >= 0, or
 * -x if x < 0.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums1 = [1,7,5], nums2 = [2,3,5]
 * Output: 3
 * Explanation: There are two possible optimal solutions:
 * - Replace the second element with the first: [1,7,5] => [1,1,5], or
 * - Replace the second element with the third: [1,7,5] => [1,5,5].
 * Both will yield an absolute sum difference of |1-2| + (|1-3| or |5-3|) +
 * |5-5| = 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums1 = [2,4,6,8,10], nums2 = [2,4,6,8,10]
 * Output: 0
 * Explanation: nums1 is equal to nums2 so no replacement is needed. This will
 * result in an 
 * absolute sum difference of 0.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums1 = [1,10,4,4,2,7], nums2 = [9,3,5,1,7,4]
 * Output: 20
 * Explanation: Replace the first element with the second: [1,10,4,4,2,7] =>
 * [10,10,4,4,2,7].
 * This yields an absolute sum difference of |10-9| + |10-3| + |4-5| + |4-1| +
 * |2-7| + |7-4| = 20
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == nums1.length
 * n == nums2.length
 * 1 <= n <= 10^5
 * 1 <= nums1[i], nums2[i] <= 10^5
 * 
 * 
 */

#include "common.hpp"

class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        const int modulo = (int) (1e9 + 7);
        // sort nums1, for each num in nums2, find the closest one in nums1 O(nlogn)
        std::vector<int> nums1_clone (nums1);
        std::sort(nums1_clone.begin(), nums1_clone.end());
        int min_absolute_sum_diff = 0;
        int max_decrease = 0;
        for (int i = 0; i < nums1.size(); i++) {
            int curr_diff = abs(nums1.at(i) - nums2.at(i));
            min_absolute_sum_diff += curr_diff;
            min_absolute_sum_diff = min_absolute_sum_diff % modulo;
            // find the num in nums1_clone using binary search
            int closest_diff = this->findClosest(nums1_clone, nums2.at(i));
            int decrease = curr_diff - closest_diff;
            if (decrease > max_decrease) {
                max_decrease = decrease;
            }
        }
        int result = min_absolute_sum_diff - max_decrease;
        if (result < 0) result = result + modulo;
        return result;
    }

private:
    int findClosest(const vector<int> &num, int target) {
        int start = 0;
        int end = num.size() - 1;
        if (target < num[start]) return num[start] - target;
        if (target > num[end]) return target - num[end];
        int mid;
        while (end - start > 1) {
            mid = (start + end) / 2;
            if (target > num[mid]) {
                start = mid;
            } else {
                end = mid;
            }
        }
        return std::min(abs(target - num[start]), abs(target - num[end]));
    }
};
