/*
 * @lc app=leetcode id=1361 lang=cpp
 *
 * [1361] Validate Binary Tree Nodes
 *
 * https://leetcode.com/problems/validate-binary-tree-nodes/description/
 *
 * algorithms
 * Medium (42.92%)
 * Total Accepted:    26.3K
 * Total Submissions: 62.3K
 * Testcase Example:  '4\n[1,-1,3,-1]\n[2,-1,-1,-1]'
 *
 * You have n binary tree nodes numbered from 0 to n - 1 where node i has two
 * children leftChild[i] and rightChild[i], return true if and only if all the
 * given nodes form exactly one valid binary tree.
 * 
 * If node i has no left child then leftChild[i] will equal -1, similarly for
 * the right child.
 * 
 * Note that the nodes have no values and that we only use the node numbers in
 * this problem.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,-1,-1,-1]
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,3,-1,-1]
 * Output: false
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 2, leftChild = [1,0], rightChild = [-1,-1]
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: n = 6, leftChild = [1,-1,-1,4,-1,-1], rightChild = [2,-1,-1,5,-1,-1]
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 10^4
 * leftChild.length == rightChild.length == n
 * -1 <= leftChild[i], rightChild[i] <= n - 1
 * 
 * 
 */

#include "common.hpp"

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        // In a valid binary tree, each node has exactly one parent and there is only one node that has no parent.
        std::vector<int> parents (n, 0);
        for (size_t i = 0; i < n; i++) {
            int parent = i;
            int left_child = leftChild[i];
            if (left_child != -1) {
                if (parents[left_child] != 0) return false;
                parents[left_child] += 1;
            }
            int right_child = rightChild[i];
            if (right_child != -1) {
                if (parents[right_child] != 0) return false;
                parents[right_child] += 1;
            }
        }
        int root = -1;
        for (int i = 0; i < n; i++) {
            if (parents[i] != 0) continue;
            if (parents[i] == 0 && root != -1) {
                return false;
            } else {
                root = i;
            }
        }
        if (root == -1) return false;

        // dfs from root to detect cycle
        std::vector<bool> visited (n, false);
        std::queue<int> frontier;
        int num_visited = 0;
        frontier.push(root);
        while (!frontier.empty()) {
            int curr = frontier.front();
            frontier.pop();
            num_visited += 1;
            if (visited[curr]) return false;
            visited[curr] = true;
            if (leftChild[curr] != -1) {
                frontier.push(leftChild[curr]);
            }
            if (rightChild[curr] != -1) {
                frontier.push(rightChild[curr]);
            }
        }
        if (num_visited != n) return false;
        
        return true;
    }
};


int main() {
    auto left = std::vector<int> {1, 0};
    auto right = std::vector<int> {-1, -1};
    std::cout << Solution().validateBinaryTreeNodes(2, left, right) << std::endl;
}