/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (50.68%)
 * Total Accepted:    314.3K
 * Total Submissions: 610.5K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * Given two integer arrays inorder and postorder where inorder is the inorder
 * traversal of a binary tree and postorder is the postorder traversal of the
 * same tree, construct and return the binary tree.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
 * Output: [3,9,20,null,null,15,7]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: inorder = [-1], postorder = [-1]
 * Output: [-1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= inorder.length <= 3000
 * postorder.length == inorder.length
 * -3000 <= inorder[i], postorder[i] <= 3000
 * inorder and postorder consist of unique values.
 * Each value of postorder also appears in inorder.
 * inorder is guaranteed to be the inorder traversal of the tree.
 * postorder is guaranteed to be the postorder traversal of the tree.
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size() == 0) return nullptr;
        // postorder: left + right + val
        // inorder: left + val + right
        return this->helper(postorder, inorder, 0, postorder.size(), 0, inorder.size());
    }

private:
    TreeNode* helper(vector<int>& postorder, vector<int>& inorder, 
                    int post_start, int post_end, int in_start, int in_end) {
        // current node
        int currVal = postorder[post_end - 1];
        // find the value in inorder
        int i;
        for (i = in_start; i < in_end; i++) {
            if (inorder[i] == currVal) break;
        }
        TreeNode* current = new TreeNode(currVal);
        if (i != in_start) {
            // find the post_end
            TreeNode* left = this->helper(postorder, inorder, post_start, i - in_start + post_start,
                                          in_start, i);
            current->left = left;
        }
        if (i != in_end - 1) {
            TreeNode* right = this->helper(postorder, inorder, 
                                          i - in_start + post_start, post_end - 1,
                                          i + 1, in_end);
            current->right = right;
        }
        return current;
    }
};
