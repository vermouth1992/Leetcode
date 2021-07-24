/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
 *
 * https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
 *
 * algorithms
 * Medium (53.58%)
 * Total Accepted:    481.6K
 * Total Submissions: 886.1K
 * Testcase Example:  '[1,2,5,3,4,null,6]'
 *
 * Given the root of a binary tree, flatten the tree into a "linked
 * list":
 * 
 * 
 * The "linked list" should use the same TreeNode class where the right child
 * pointer points to the next node in the list and the left child pointer is
 * always null.
 * The "linked list" should be in the same order as a pre-order traversal of
 * the binary tree.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,2,5,3,4,null,6]
 * Output: [1,null,2,null,3,null,4,null,5,null,6]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = []
 * Output: []
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: root = [0]
 * Output: [0]
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
 * 
 * Follow up: Can you flatten the tree in-place (with O(1) extra space)?
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
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        vector<TreeNode*> preorder_lst;
        this->preorder(preorder_lst, root);
        for (int i = 0; i < preorder_lst.size() - 1; i++) {
            auto node = preorder_lst.at(i);
            node->left = nullptr;
            node->right = preorder_lst.at(i + 1);
        }
        auto last_node = preorder_lst.at(preorder_lst.size() - 1);
        last_node->left = nullptr;
        last_node->right = nullptr;
    }

private:
    void preorder(vector<TreeNode*> &preorder_lst, TreeNode* root) {
        if (root == nullptr) return;
        preorder_lst.push_back(root);
        this->preorder(preorder_lst, root->left);
        this->preorder(preorder_lst, root->right);
    }
};
