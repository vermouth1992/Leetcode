/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (58.38%)
 * Total Accepted:    534.8K
 * Total Submissions: 912K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
 * 
 * Example:
 * 
 * 
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * Output: [1,3,2]
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
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> result;
        std::stack<TreeNode*> helperStack;
        TreeNode* current = root;

        // push all the left to the stack
        while (current != nullptr) {
            helperStack.push(current);
            current = current->left;
        }

        while (!helperStack.empty()) {
            current = helperStack.top();
            helperStack.pop();
            result.push_back(current->val);
            current = current->right;
            while (current != nullptr) {
                helperStack.push(current);
                current = current->left;
            }
        }
        return result;
    }
};
