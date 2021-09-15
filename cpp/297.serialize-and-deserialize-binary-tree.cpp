/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 *
 * https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
 *
 * algorithms
 * Hard (50.72%)
 * Total Accepted:    495.9K
 * Total Submissions: 958.5K
 * Testcase Example:  '[1,2,3,null,null,4,5]'
 *
 * Serialization is the process of converting a data structure or object into a
 * sequence of bits so that it can be stored in a file or memory buffer, or
 * transmitted across a network connection link to be reconstructed later in
 * the same or another computer environment.
 * 
 * Design an algorithm to serialize and deserialize a binary tree. There is no
 * restriction on how your serialization/deserialization algorithm should work.
 * You just need to ensure that a binary tree can be serialized to a string and
 * this string can be deserialized to the original tree structure.
 * 
 * Clarification: The input/output format is the same as how LeetCode
 * serializes a binary tree. You do not necessarily need to follow this format,
 * so please be creative and come up with different approaches yourself.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,2,3,null,null,4,5]
 * Output: [1,2,3,null,null,4,5]
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
 * Input: root = [1]
 * Output: [1]
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: root = [1,2]
 * Output: [1,2]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [0, 10^4].
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include "common.hpp"

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // val(left)right
        if (root == nullptr) return std::string();
        std::string left = this->serialize(root->left);
        std::string right = this->serialize(root->right);
        std::string result = std::to_string(root->val);
        result.append(1, '(');
        result.append(left);
        result.append(1, ')');
        result.append(right);
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // construct parenthesis mapping table. O(N)
        std::unordered_map<int, int> table;
        std::stack<int> s;
        for (int i = 0; i < data.size(); i++) {
            if (data.at(i) == '(') {
                s.push(i);
            } else if (data.at(i) == ')') {
                int top = s.top();
                table[top] = i;
                s.pop();
            }
        }
        return this->deserialize_helper(data, 0, data.size() - 1, table);
    }

    TreeNode* deserialize_helper(const std::string &data, int left, int right, const std::unordered_map<int, int> & table) {
        if (left >= right) return nullptr;
        // find the first left parenthesis
        int left_index;
        int num = 0;
        bool positive = true;
        for (int i = left; i <= right; i++) {
            if (data.at(i) == '(') {
                left_index = i;
                break;
            } else if (data.at(i) == '-') {
                positive = false;
            } else {
                int digit = (int) (data.at(i) - '0');
                num = num * 10 + digit;
            }
        }
        if (!positive) num = -num;
        int right_index = table.at(left_index);
        TreeNode *left_child = this->deserialize_helper(data, left_index + 1, right_index - 1, table);
        TreeNode *right_child = this->deserialize_helper(data, right_index + 1, right, table);
        TreeNode *root = new TreeNode(num);
        root->left = left_child;
        root->right = right_child;
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
