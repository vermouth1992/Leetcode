/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Hard (50.14%)
 * Total Accepted:    292K
 * Total Submissions: 579.7K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the postorder traversal of its nodes' values.
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
 * Output: [3,2,1]
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
    vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> result;
        std::stack<TreeNode*> helperStack1;
        std::stack<int> helperStack2;
        TreeNode* current = root;
        if (current != nullptr) helperStack1.push(current);
        while (!helperStack1.empty())
        {
            current = helperStack1.top();
            helperStack1.pop();
            helperStack2.push(current->val);
            if (current->left != nullptr) helperStack1.push(current->left);
            if (current->right != nullptr)helperStack1.push(current->right);
        }
        while (!helperStack2.empty())
        {
            result.push_back(helperStack2.top());
            helperStack2.pop();
        }
        return result;
    }
};
