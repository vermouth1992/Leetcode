/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
 *
 * https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
 *
 * algorithms
 * Hard (35.89%)
 * Total Accepted:    578K
 * Total Submissions: 1.6M
 * Testcase Example:  '[1,2,3]'
 *
 * A path in a binary tree is a sequence of nodes where each pair of adjacent
 * nodes in the sequence has an edge connecting them. A node can only appear in
 * the sequence at most once. Note that the path does not need to pass through
 * the root.
 * 
 * The path sum of a path is the sum of the node's values in the path.
 * 
 * Given the root of a binary tree, return the maximum path sum of any path.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,2,3]
 * Output: 6
 * Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 =
 * 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [-10,9,20,null,null,15,7]
 * Output: 42
 * Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 +
 * 7 = 42.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 3 * 10^4].
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
    int maxPathSum(TreeNode* root) {
        int result = std::numeric_limits<int>::min();
        this->helper(root, result);
        return result;
    }

private:
    // helper function that return the maximum path that starting from the current node
    int helper(TreeNode* node, int &result) {
        if (node == nullptr) {
            return 0;
        }

        int left_max = this->helper(node->left, result);
        int right_max = this->helper(node->right, result);
        int sub_path_max = std::max(left_max, right_max); // choose the path with maximum value
        sub_path_max = std::max(sub_path_max, 0); // if it is smaller than zero, we ignore the path
        // maximum path value that pass the current node
        int current_path_val = node->val + std::max(left_max, 0) + std::max(right_max, 0);
        result = std::max(result, current_path_val);
        return sub_path_max + node->val;
    }
};
