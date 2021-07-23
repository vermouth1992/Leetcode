/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (53.01%)
 * Total Accepted:    547.2K
 * Total Submissions: 1M
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * Given two integer arrays preorder and inorder where preorder is the preorder
 * traversal of a binary tree and inorder is the inorder traversal of the same
 * tree, construct and return the binary tree.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 * Output: [3,9,20,null,null,15,7]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: preorder = [-1], inorder = [-1]
 * Output: [-1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= preorder.length <= 3000
 * inorder.length == preorder.length
 * -3000 <= preorder[i], inorder[i] <= 3000
 * preorder and inorder consist of unique values.
 * Each value of inorder also appears in preorder.
 * preorder is guaranteed to be the preorder traversal of the tree.
 * inorder is guaranteed to be the inorder traversal of the tree.
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return nullptr;
        // preorder: val + left + right
        // inorder: left + val + right
        return this->helper(preorder, inorder, 0, preorder.size(), 0, inorder.size());
    }

private:
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, 
                    int pre_start, int pre_end, int in_start, int in_end) {
        // current node
        int currVal = preorder[pre_start];
        // find the value in inorder
        int i;
        for (i = in_start; i < in_end; i++) {
            if (inorder[i] == currVal) break;
        }
        TreeNode* current = new TreeNode(currVal);
        if (i != in_start) {
            // find the pre_end
            TreeNode* left = this->helper(preorder, inorder, pre_start + 1, i - in_start + pre_start + 1,
                                          in_start, i);
            current->left = left;
        }
        if (i != in_end - 1) {
            TreeNode* right = this->helper(preorder, inorder, 
                                          i - in_start + pre_start + 1, pre_end,
                                          i + 1, in_end);
            current->right = right;
        }
        return current;
    }
};
