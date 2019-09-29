/*
 * @lc app=leetcode id=589 lang=cpp
 *
 * [589] N-ary Tree Preorder Traversal
 *
 * https://leetcode.com/problems/n-ary-tree-preorder-traversal/description/
 *
 * algorithms
 * Easy (68.80%)
 * Total Accepted:    60K
 * Total Submissions: 87.1K
 * Testcase Example:  '{"$id":"1","children":[{"$id":"2","children":[{"$id":"5","children":[],"val":5},{"$id":"6","children":[],"val":6}],"val":3},{"$id":"3","children":[],"val":2},{"$id":"4","children":[],"val":4}],"val":1}'
 *
 * Given an n-ary tree, return the preorder traversal of its nodes' values.
 * 
 * For example, given a 3-ary tree:
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Return its preorder traversal as: [1,3,5,6,2,4].
 * 
 * 
 * 
 * Note:
 * 
 * Recursive solution is trivial, could you do it iteratively?
 * 
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

#include "common.hpp"
#include <vector>
#include <stack>

using namespace std;


class Solution {
public:
    vector<int> preorder(Node* root) {
        std::vector<int> result;
        std::stack<Node*> helperStack;
        Node* current = root;
        if (current != nullptr) helperStack.push(current);
        while (!helperStack.empty())
        {
            current = helperStack.top();
            result.push_back(current->val);
            helperStack.pop();
            for (int i = current->children.size() - 1; i >= 0; i--) {
                helperStack.push(current->children[i]);
            }
        }
        return result;
    }
};
