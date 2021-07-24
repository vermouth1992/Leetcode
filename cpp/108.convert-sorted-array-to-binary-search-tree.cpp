/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (61.51%)
 * Total Accepted:    568.1K
 * Total Submissions: 911.5K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * Given an integer array nums where the elements are sorted in ascending
 * order, convert it to a height-balanced binary search tree.
 * 
 * A height-balanced binary tree is a binary tree in which the depth of the two
 * subtrees of every node never differs by more than one.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [-10,-3,0,5,9]
 * Output: [0,-3,9,-10,null,5]
 * Explanation: [0,-10,5,null,-3,null,9] is also accepted:
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,3]
 * Output: [3,1]
 * Explanation: [1,3] and [3,1] are both a height-balanced BSTs.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^4
 * -10^4 <= nums[i] <= 10^4
 * nums is sorted in a strictly increasing order.
 * 
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include "common.hpp"

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // divide and conquer
        return this->helper(nums, 0, nums.size());
    }

private:
    TreeNode* helper(vector<int>& nums, int start, int end) {
        if (end - start == 0) return nullptr;
        if (end - start == 1) {
            // only start
            return new TreeNode(nums[start]);
        }
        int mid = (start + end) / 2;
        TreeNode *leftChild = this->helper(nums, start, mid);
        TreeNode *rightChild = this->helper(nums, mid + 1, end);
        TreeNode *currentNode = new TreeNode(nums[mid], leftChild, rightChild);
        return currentNode;
    }
};
