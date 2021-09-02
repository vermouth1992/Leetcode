/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
 *
 * https://leetcode.com/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (43.54%)
 * Total Accepted:    256K
 * Total Submissions: 559.7K
 * Testcase Example:  '3'
 *
 * Given an integer n, return all the structurally unique BST's (binary search
 * trees), which has exactly n nodes of unique values from 1 to n. Return the
 * answer in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 3
 * Output:
 * [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 1
 * Output: [[1]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 8
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
    vector<TreeNode*> generateTrees(int n) {
        return this->helper(1, n);
    }

private:
    std::unordered_map<int, std::vector<TreeNode*>> cache;

    vector<TreeNode*> helper(int left, int right) {
        auto key = left * 31 + right;
        if (cache.find(key) != cache.end()) {
            return cache.at(key);
        }
        // base case
        std::vector<TreeNode*> result;
        if (left > right) {
            result.push_back(nullptr);
            return result;
        }

        for (int root = left; root <= right; root++) {
            auto left_trees = this->helper(left, root - 1);
            auto right_trees = this->helper(root + 1, right);
            for (auto &left_tree: left_trees) {
                for (auto &right_tree : right_trees) {
                    TreeNode* root_node = new TreeNode(root, left_tree, right_tree);
                    result.push_back(root_node);
                }
            }
        }
        cache[key] = result;
        return result;
    }
};
