/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (49.69%)
 * Total Accepted:    440.5K
 * Total Submissions: 881.6K
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * Find the kth largest element in an unsorted array. Note that it is the kth
 * largest element in the sorted order, not the kth distinct element.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,1,5,6,4] and k = 2
 * Output: 5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,3,1,2,4,5,5,6] and k = 4
 * Output: 4
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 * 
 */

#include "common.hpp"

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // maintain a min priority queue of size k. Complexity. O(nlogk)
        std::priority_queue<int, vector<int>, std::greater<int>> minPQ;
        for (int i = 0; i < k; i++) {
            minPQ.push(nums[i]);
        }
        for (int i = k; i < nums.size(); i++) {
            minPQ.push(nums[i]);
            minPQ.pop();
        }
        return minPQ.top();
    }
};
