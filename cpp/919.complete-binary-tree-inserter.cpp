/*
 * @lc app=leetcode id=919 lang=cpp
 *
 * [919] Complete Binary Tree Inserter
 *
 * https://leetcode.com/problems/complete-binary-tree-inserter/description/
 *
 * algorithms
 * Medium (59.45%)
 * Total Accepted:    27.1K
 * Total Submissions: 44.9K
 * Testcase Example:  '["CBTInserter","insert","insert","get_root"]\n[[[1,2]],[3],[4],[]]'
 *
 * A complete binary tree is a binary tree in which every level, except
 * possibly the last, is completely filled, and all nodes are as far left as
 * possible.
 * 
 * Design an algorithm to insert a new node to a complete binary tree keeping
 * it complete after the insertion.
 * 
 * Implement the CBTInserter class:
 * 
 * 
 * CBTInserter(TreeNode root) Initializes the data structure with the root of
 * the complete binary tree.
 * int insert(int v) Inserts a TreeNode into the tree with value Node.val ==
 * val so that the tree remains complete, and returns the value of the parent
 * of the inserted TreeNode.
 * TreeNode get_root() Returns the root node of the tree.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input
 * ["CBTInserter", "insert", "insert", "get_root"]
 * [[[1, 2]], [3], [4], []]
 * Output
 * [null, 1, 2, [1, 2, 3, 4]]
 * 
 * Explanation
 * CBTInserter cBTInserter = new CBTInserter([1, 2]);
 * cBTInserter.insert(3);  // return 1
 * cBTInserter.insert(4);  // return 2
 * cBTInserter.get_root(); // return [1, 2, 3, 4]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree will be in the range [1, 1000].
 * 0 <= Node.val <= 5000
 * root is a complete binary tree.
 * 0 <= val <= 5000
 * At most 10^4 calls will be made to insert and get_root.
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

class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        initialize(root, 1);
    }
    
    int insert(int val) {
        // O(1) time. maintain the binary tree as a heap structure using array
        auto new_node = new TreeNode(val);
        int current_index = nodes.size();
        auto parent = nodes.at(current_index / 2);
        if (current_index % 2 == 0) {
            parent->left = new_node;
        } else {
            parent->right = new_node;
        }
        nodes.push_back(new_node);
        return parent->val;
    }
    
    TreeNode* get_root() {
        return nodes[1];
    }

private:
    vector<TreeNode*> nodes {nullptr};

    void initialize(TreeNode* root, int index) {
        if (root == nullptr) return;
        if (nodes.size() < index + 1) {
            nodes.resize(index + 1, nullptr);
        }
        nodes[index] = root;
        initialize(root->left, index * 2);
        initialize(root->right, index * 2 + 1);
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
