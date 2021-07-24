/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
 *
 * https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (40.17%)
 * Total Accepted:    594.6K
 * Total Submissions: 1.5M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, find its minimum depth.
 * 
 * The minimum depth is the number of nodes along the shortest path from the
 * root node down to the nearest leaf node.
 * 
 * Note: A leaf is a node with no children.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [3,9,20,null,null,15,7]
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [2,null,3,null,4,null,5,null,6]
 * Output: 5
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [0, 10^5].
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
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int result = 0;
        queue<TreeNode*> frontier;
        frontier.push(root);
        int currentSize = 1;
        while (!frontier.empty())
        {
            int size = 0;
            result += 1;
            bool hasLeaf = false;
            for (size_t i = 0; i < currentSize; i++)
            {
                auto node = frontier.front();
                frontier.pop();
                bool hasLeft = node->left != nullptr;
                bool hasRight = node->right != nullptr;

                if (!hasLeft && !hasRight) {
                    hasLeaf = true;
                    break;
                }
                
                if (hasLeft) {
                    frontier.push(node->left);
                    size += 1;
                }
                if (hasRight) {
                    frontier.push(node->right);
                    size += 1;
                }
            }
            currentSize = size;
            if (hasLeaf) break;
            
        }
        return result;
    }
};
