/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 *
 * https://leetcode.com/problems/find-the-duplicate-number/description/
 *
 * algorithms
 * Medium (50.96%)
 * Total Accepted:    222.8K
 * Total Submissions: 435.8K
 * Testcase Example:  '[1,3,4,2,2]'
 *
 * Given an array nums containing n + 1 integers where each integer is between
 * 1 and n (inclusive), prove that at least one duplicate number must exist.
 * Assume that there is only one duplicate number, find the duplicate one.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,3,4,2,2]
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,1,3,4,2]
 * Output: 3
 * 
 * Note:
 * 
 * 
 * You must not modify the array (assume the array is read only).
 * You must use only constant, O(1) extra space.
 * Your runtime complexity should be less than O(n2).
 * There is only one duplicate number in the array, but it could be repeated
 * more than once.
 * 
 * 
 */

#include "common.hpp"

class Solution {
private:
    int getNext(vector<int>& nums, int currentIndex) {
        return nums[currentIndex];
    }

public:
    int findDuplicate(vector<int>& nums) {
        // the problem can be reduced to detect cycles in the linked list, 
        // where the nums[i]->next = nums[nums[i]];
        int head = 0;
        int slow = head;
        int fast = getNext(nums, head);
        while (slow != fast)
        {
            fast = getNext(nums, fast);
            fast = getNext(nums, fast);
            slow = getNext(nums, slow);
        }
        // find the point in the loop that has the same distance from head to starting point.
        fast = getNext(nums, head);
        for (int node = getNext(nums, slow); node != slow; node = getNext(nums, node)) {
            fast = getNext(nums, fast);
        }
        slow = head;
        while (slow != fast)
        {
            slow = getNext(nums, slow);
            fast = getNext(nums, fast);
        }
        return slow;
    }
};
