/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 *
 * https://leetcode.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (44.34%)
 * Total Accepted:    466.6K
 * Total Submissions: 1M
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric
 * around its center).
 * 
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 * 
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 
 * 
 * But the following [1,2,2,null,3,null,3] is not:
 * 
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 
 * 
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
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

#include "common.hpp"

class Solution {
private:
    bool isSymmetricHelper(TreeNode* left, TreeNode* right) {
        // two trees are symmetric if left->left is symmetric to right->right and left->right symmetric
        // to right->left
        if (left == NULL && right == NULL) return true;
        if (left != NULL && right != NULL) {
            if (left->val != right->val) return false;
            return isSymmetricHelper(left->left, right->right) & isSymmetricHelper(left->right, right->left);
        }
        return false;
    }

public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return isSymmetricHelper(root->left, root->right);
    }
};
