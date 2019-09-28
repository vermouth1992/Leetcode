/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 *
 * https://leetcode.com/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (26.25%)
 * Total Accepted:    475.5K
 * Total Submissions: 1.8M
 * Testcase Example:  '[2,1,3]'
 *
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 * 
 * Assume a BST is defined as follows:
 * 
 * 
 * The left subtree of a node contains only nodes with keys less than the
 * node's key.
 * The right subtree of a node contains only nodes with keys greater than the
 * node's key.
 * Both the left and right subtrees must also be binary search trees.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * ⁠   2
 * ⁠  / \
 * ⁠ 1   3
 * 
 * Input: [2,1,3]
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * ⁠   5
 * ⁠  / \
 * ⁠ 1   4
 * / \
 * 3   6
 * 
 * Input: [5,1,4,null,null,3,6]
 * Output: false
 * Explanation: The root node's value is 5 but its right child's value is 4.
 * 
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
 * Note: use pointer instead max value to avoid corner case.
 */


#include "common.hpp"

class Solution {
private:
    bool isValidBSTHelper(TreeNode* root, int* min, int* max) {
        if (root ==  nullptr) return true;

        if (min != nullptr && root->val <= *min) return false;
        if (max != nullptr && root->val >= *max) return false;

        int *valPointer = new int(root->val);
        if (!isValidBSTHelper(root->left, min, valPointer)) {
            delete valPointer;
            return false;
        }
        if (!isValidBSTHelper(root->right, valPointer, max)) {
            delete valPointer;
            return false;
        }
        delete valPointer;
        return true;
    }

public:
    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root, nullptr, nullptr);
    }
};
