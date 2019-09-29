/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Medium (52.52%)
 * Total Accepted:    380.2K
 * Total Submissions: 721.6K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the preorder traversal of its nodes' values.
 * 
 * Example:
 * 
 * 
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * Output: [1,2,3]
 * 
 * 
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> result;
        std::stack<TreeNode*> helperStack;
        TreeNode* current = root;
        if (current != nullptr) helperStack.push(current);
        while (!helperStack.empty())
        {
            current = helperStack.top();
            result.push_back(current->val);
            helperStack.pop();
            if (current->right != nullptr) helperStack.push(current->right);
            if (current->left != nullptr) helperStack.push(current->left);
        }
        return result;
    }
};
