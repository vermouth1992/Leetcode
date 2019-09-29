/*
 * @lc app=leetcode id=429 lang=cpp
 *
 * [429] N-ary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/n-ary-tree-level-order-traversal/description/
 *
 * algorithms
 * Easy (60.67%)
 * Total Accepted:    46.5K
 * Total Submissions: 76.5K
 * Testcase Example:  '{"$id":"1","children":[{"$id":"2","children":[{"$id":"5","children":[],"val":5},{"$id":"6","children":[],"val":6}],"val":3},{"$id":"3","children":[],"val":2},{"$id":"4","children":[],"val":4}],"val":1}'
 *
 * Given an n-ary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
 * 
 * For example, given a 3-ary tree:
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * We should return its level order traversal:
 * 
 * 
 * [
 * ⁠    [1],
 * ⁠    [3,2,4],
 * ⁠    [5,6]
 * ]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The depth of the tree is at most 1000.
 * The total number of nodes is at most 5000.
 * 
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
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        std::vector<std::vector<int>> result;
        std::queue<Node*>* helperQueueCurrentLevel = new std::queue<Node*>();
        std::queue<Node*>* helperQueueNextLevel = new std::queue<Node*>();
        Node* current = root;
        if (current != nullptr) helperQueueCurrentLevel->push(current);
        while (!helperQueueCurrentLevel->empty())
        {
            std::vector<int> temp;
            // pop all the element in the current level and push to temp
            while (!helperQueueCurrentLevel->empty())
            {
                Node *front = helperQueueCurrentLevel->front();
                helperQueueCurrentLevel->pop();
                for (auto node : front->children) {
                    helperQueueNextLevel->push(node);
                }
                temp.push_back(front->val);
            }
            result.push_back(temp);
            
            std::swap(helperQueueCurrentLevel, helperQueueNextLevel);
        }
        return result;
    }
};
