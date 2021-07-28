/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 *
 * https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/
 *
 * algorithms
 * Medium (50.31%)
 * Total Accepted:    524.8K
 * Total Submissions: 1M
 * Testcase Example:  '[1,2,3,4,5,6,7]'
 *
 * You are given a perfect binary tree where all leaves are on the same level,
 * and every parent has two children. The binary tree has the following
 * definition:
 * 
 * 
 * struct Node {
 * ⁠ int val;
 * ⁠ Node *left;
 * ⁠ Node *right;
 * ⁠ Node *next;
 * }
 * 
 * 
 * Populate each next pointer to point to its next right node. If there is no
 * next right node, the next pointer should be set to NULL.
 * 
 * Initially, all next pointers are set to NULL.
 * 
 * 
 * 
 * Follow up:
 * 
 * 
 * You may only use constant extra space.
 * Recursive approach is fine, you may assume implicit stack space does not
 * count as extra space for this problem.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: root = [1,2,3,4,5,6,7]
 * Output: [1,#,2,3,#,4,5,6,7,#]
 * Explanation: Given the above perfect binary tree (Figure A), your function
 * should populate each next pointer to point to its next right node, just like
 * in Figure B. The serialized output is in level order as connected by the
 * next pointers, with '#' signifying the end of each level.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the given tree is less than 4096.
 * -1000 <= node.val <= 1000
 * 
 */

// Definition for a Node.

#include "common.hpp"

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) return root;

        deque<Node *> current_level {root};
        int current_size = 1;
        while (!current_level.empty()) {
            int temp_size = 0;
            // set right pointer
            if (current_level.size() > 1) {
                auto it = current_level.begin();
                Node *first = NULL;
                Node *second = NULL;
                while (it != current_level.end()) {
                    if (first == NULL) {
                        first = *it;
                    } else if (second == NULL) {
                        second = *it;
                        first->next = second;
                    } else {
                        first = second;
                        second = *it;
                        first->next = second;
                    }
                    it++;
                }
            }
            // get the next level
            for (int i = 0; i < current_size; i++) {
                Node* node = current_level.front();
                current_level.pop_front();
                if (node->left != NULL) {
                    current_level.push_back(node->left);
                    temp_size += 1;
                }
                if (node->right != NULL) {
                    current_level.push_back(node->right);
                    temp_size += 1;
                }
            }
            current_size = temp_size;
        }
        return root;
    }
};
