/*
 * @lc app=leetcode id=590 lang=cpp
 *
 * [590] N-ary Tree Postorder Traversal
 *
 * https://leetcode.com/problems/n-ary-tree-postorder-traversal/description/
 *
 * algorithms
 * Easy (68.82%)
 * Total Accepted:    53.7K
 * Total Submissions: 78K
 * Testcase Example:  '{"$id":"1","children":[{"$id":"2","children":[{"$id":"5","children":[],"val":5},{"$id":"6","children":[],"val":6}],"val":3},{"$id":"3","children":[],"val":2},{"$id":"4","children":[],"val":4}],"val":1}'
 *
 * Given an n-ary tree, return the postorder traversal of its nodes' values.
 * 
 * For example, given a 3-ary tree:
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Return its postorder traversal as: [5,6,3,2,4,1].
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
    vector<int> postorder(Node* root) {
        std::vector<int> result;
        std::stack<Node*> helperStack1;
        std::stack<int> helperStack2;
        Node* current = root;
        if (current != nullptr) helperStack1.push(current);
        while (!helperStack1.empty())
        {
            current = helperStack1.top();
            helperStack1.pop();
            helperStack2.push(current->val);
            for (auto &node : current->children) {
                helperStack1.push(node);
            }
        }
        while (!helperStack2.empty())
        {
            result.push_back(helperStack2.top());
            helperStack2.pop();
        }
        return result;
    }
};
