/*
 * @lc app=leetcode id=814 lang=cpp
 *
 * [814] Binary Tree Pruning
 *
 * https://leetcode.com/problems/binary-tree-pruning/description/
 *
 * algorithms
 * Medium (71.73%)
 * Total Accepted:    108K
 * Total Submissions: 150.9K
 * Testcase Example:  '[1,null,0,0,1]'
 *
 * Given the root of a binary tree, return the same tree where every subtree
 * (of the given tree) not containing a 1 has been removed.
 * 
 * A subtree of a node node is node plus every node that is a descendant of
 * node.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,null,0,0,1]
 * Output: [1,null,0,null,1]
 * Explanation: 
 * Only the red nodes satisfy the property "every subtree not containing a 1".
 * The diagram on the right represents the answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1,0,1,0,0,0,1]
 * Output: [1,null,1,null,1]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: root = [1,1,0,1,1,0,1,0]
 * Output: [1,1,0,1,1,null,1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 200].
 * Node.val is either 0 or 1.
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
    TreeNode* pruneTree(TreeNode* root) {
        bool treeContainingOne = this->helper(root);
        if (treeContainingOne) return root;
        else return nullptr;
    }

private:
    bool helper(TreeNode* current) {
        if (current == nullptr) {
            return false;
        }
        bool leftContainingOne = this->helper(current->left);
        if (!leftContainingOne) {
            current->left = nullptr;
        }
        bool rightContainingOne = this->helper(current->right);
        if (!rightContainingOne) {
            current->right = nullptr;
        }

        if (current->val == 1) {
            return true;
        } else {
            if ((!leftContainingOne) && (!rightContainingOne)) {
                // delete current; some bug with leetcode that access the original tree afterwards
                return false;
            } else {
                return true;
            }
        }
    }
};
