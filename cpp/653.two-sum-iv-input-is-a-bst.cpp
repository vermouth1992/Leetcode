/*
 * @lc app=leetcode id=653 lang=cpp
 *
 * [653] Two Sum IV - Input is a BST
 *
 * https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
 *
 * algorithms
 * Easy (53.23%)
 * Total Accepted:    101.7K
 * Total Submissions: 190.8K
 * Testcase Example:  '[5,3,6,2,4,null,7]\n9'
 *
 * Given a Binary Search Tree and a target number, return true if there exist
 * two elements in the BST such that their sum is equal to the given target.
 * 
 * Example 1:
 * 
 * 
 * Input: 
 * ⁠   5
 * ⁠  / \
 * ⁠ 3   6
 * ⁠/ \   \
 * 2   4   7
 * 
 * Target = 9
 * 
 * Output: True
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 
 * ⁠   5
 * ⁠  / \
 * ⁠ 3   6
 * ⁠/ \   \
 * 2   4   7
 * 
 * Target = 28
 * 
 * Output: False
 * 
 * 
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

#include<set>

class Solution {
private:
    bool findTargetHelper(TreeNode *node, int k, std::set<int> &residual) {
        if (node == NULL) return false;
        if (residual.find(node->val) != residual.end()) return true;
        residual.insert(k - node->val);
        if (findTargetHelper(node->left, k, residual)) return true;
        else return findTargetHelper(node->right, k, residual);
    }

public:
    bool findTarget(TreeNode* root, int k) {
        std::set<int> residual;
        return findTargetHelper(root, k, residual);
    }
};
