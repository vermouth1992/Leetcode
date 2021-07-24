/*
 * @lc app=leetcode id=109 lang=cpp
 *
 * [109] Convert Sorted List to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/
 *
 * algorithms
 * Medium (52.15%)
 * Total Accepted:    322K
 * Total Submissions: 609.7K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * Given the head of a singly linked list where elements are sorted in
 * ascending order, convert it to a height balanced BST.
 * 
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [-10,-3,0,5,9]
 * Output: [0,-3,9,-10,null,5]
 * Explanation: One possible answer is [0,-3,9,-10,null,5], which represents
 * the shown height balanced BST.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = []
 * Output: []
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: head = [0]
 * Output: [0]
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: head = [1,3]
 * Output: [3,1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in head is in the range [0, 2 * 10^4].
 * -10^5 <= Node.val <= 10^5
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        while (head != nullptr)
        {
            nums.push_back(head->val);
            head = head->next;
        }
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
