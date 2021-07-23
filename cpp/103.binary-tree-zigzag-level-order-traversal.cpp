/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (50.82%)
 * Total Accepted:    545.6K
 * Total Submissions: 1.1M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given the root of a binary tree, return the zigzag level order traversal of
 * its nodes' values. (i.e., from left to right, then right to left for the
 * next level and alternate between).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [3,9,20,null,null,15,7]
 * Output: [[3],[20,9],[15,7]]
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
 * -100 <= Node.val <= 100
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;
        deque<TreeNode*> current_level {root};
        deque<TreeNode*> next_level;

        auto current_level_ptr = &current_level;
        auto next_level_ptr = &next_level;

        bool left_to_right = true;

        while (true) {
            vector<int> current_level_val;
            while (current_level_ptr->size() > 0)
            {
                TreeNode* node;
                if (left_to_right) {
                    node = current_level_ptr->back();
                    current_level_ptr->pop_back();
                } else {
                    node = current_level_ptr->front();
                    current_level_ptr->pop_front();
                }
                
                // add the value
                current_level_val.push_back(node->val);
                // add the children
                if (left_to_right) {
                    if (node->left != nullptr) next_level_ptr->push_front(node->left);
                    if (node->right != nullptr) next_level_ptr->push_front(node->right);
                } else {
                    if (node->right != nullptr) next_level_ptr->push_back(node->right);
                    if (node->left != nullptr) next_level_ptr->push_back(node->left);
                }
            }
            left_to_right = !left_to_right;
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
