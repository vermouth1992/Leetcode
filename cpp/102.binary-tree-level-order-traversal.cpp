/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (57.66%)
 * Total Accepted:    911.4K
 * Total Submissions: 1.6M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given the root of a binary tree, return the level order traversal of its
 * nodes' values. (i.e., from left to right, level by level).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [3,9,20,null,null,15,7]
 * Output: [[3],[9,20],[15,7]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1]
 * Output: [[1]]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: root = []
 * Output: []
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [0, 2000].
 * -1000 <= Node.val <= 1000
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;
        queue<TreeNode*> current_level;
        queue<TreeNode*> next_level;
        current_level.push(root);

        auto current_level_ptr = &current_level;
        auto next_level_ptr = &next_level;

        while (true) {
            vector<int> current_level_val;
            while (current_level_ptr->size() > 0)
            {
                TreeNode* node = current_level_ptr->front();
                // add the value
                current_level_val.push_back(node->val);
                // add the children
                if (node->left != nullptr) next_level_ptr->push(node->left);
                if (node->right != nullptr) next_level_ptr->push(node->right);
                current_level_ptr->pop();
            }
            result.push_back(current_level_val);
            if (next_level_ptr->size() == 0) break;
            // switch pointer
            auto temp = current_level_ptr;
            current_level_ptr = next_level_ptr;
            next_level_ptr = temp;
        }
        return result;
    }
};
