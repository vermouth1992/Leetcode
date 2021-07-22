/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
 *
 * https://leetcode.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (50.01%)
 * Total Accepted:    438.9K
 * Total Submissions: 866.2K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * Given the root of a binary tree and an integer targetSum, return all
 * root-to-leaf paths where each path's sum equals targetSum.
 * 
 * A leaf is a node with no children.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
 * Output: [[5,4,11,2],[5,8,4,5]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1,2,3], targetSum = 5
 * Output: []
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: root = [1,2], targetSum = 0
 * Output: []
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [0, 5000].
 * -1000 <= Node.val <= 1000
 * -1000 <= targetSum <= 1000
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> curr;
        if (root != nullptr) {
            this->helper(result, curr, root, targetSum);
        }
        return result;
    }

private:
    void helper(vector<vector<int>> &result, vector<int> &curr, TreeNode* currentNode, int leftSum) {
        // leaf node
        curr.push_back(currentNode->val);
        leftSum = leftSum - currentNode->val;

        if (currentNode->left == nullptr && currentNode->right == nullptr) {
            if (leftSum == 0) {
                result.push_back(vector(curr));
            }
        }
        
        if (currentNode->left != nullptr) {
            this->helper(result, curr, currentNode->left, leftSum);
        }
        if (currentNode->right != nullptr) {
            this->helper(result, curr, currentNode->right, leftSum);
        }
        
        curr.pop_back();
    }
};
