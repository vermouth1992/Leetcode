/*
 * @lc app=leetcode id=331 lang=cpp
 *
 * [331] Verify Preorder Serialization of a Binary Tree
 *
 * https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (41.28%)
 * Total Accepted:    96.9K
 * Total Submissions: 226.8K
 * Testcase Example:  '"9,3,4,#,#,1,#,#,2,#,6,#,#"'
 *
 * One way to serialize a binary tree is to use preorder traversal. When we
 * encounter a non-null node, we record the node's value. If it is a null node,
 * we record using a sentinel value such as '#'.
 * 
 * For example, the above binary tree can be serialized to the string
 * "9,3,4,#,#,1,#,#,2,#,6,#,#", where '#' represents a null node.
 * 
 * Given a string of comma-separated values preorder, return true if it is a
 * correct preorder traversal serialization of a binary tree.
 * 
 * It is guaranteed that each comma-separated value in the string must be
 * either an integer or a character '#' representing null pointer.
 * 
 * You may assume that the input format is always valid.
 * 
 * 
 * For example, it could never contain two consecutive commas, such as
 * "1,,3".
 * 
 * 
 * Note: You are not allowed to reconstruct the tree.
 * 
 * 
 * Example 1:
 * Input: preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#"
 * Output: true
 * Example 2:
 * Input: preorder = "1,#"
 * Output: false
 * Example 3:
 * Input: preorder = "9,#,#,1"
 * Output: false
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= preorder.length <= 10^4
 * preoder consist of integers in the range [0, 100] and '#' separated by
 * commas ','.
 * 
 * 
 */

#include "common.hpp"

class Solution {
public:
    bool isValidSerialization(string preorder) {
        // create a stack and mark each root node as left or right. If top is "left", mark as "right". If top is "right", pop it. Left: true, right: false
        std::stack<bool> helper;  // we actually don't care about the root value
        int index = 0;
        bool prev_num = true;
        while (index < preorder.size()) {
            if (preorder[index] >= '0' && preorder[index] <= '9') {
                prev_num = true;
            }
            else if (preorder[index] == '#') {
                prev_num = false;
            } else if (preorder[index] == ',') {
                // push the current value
                if (prev_num) {
                    helper.push(true);   // mark as left
                } else {
                    // check the top of the stack, if it is true, pop it and push false
                    // if it is false, pop it
                    if (helper.empty()) return false;
                    while (!helper.top()) {
                        helper.pop();
                        if (helper.empty()) return false;
                    }
                    helper.pop();
                    helper.push(false);
                }
            }
            index += 1;
        }
        // the last one
        if (prev_num) return false;
        // everything should be false
        while (!helper.empty()) {
            if (helper.top()) return false;
            else helper.pop();
        }
        // at the end, the stack must be empty
        return true;
    }
};
