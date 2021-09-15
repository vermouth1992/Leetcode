/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 *
 * https://leetcode.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (44.40%)
 * Total Accepted:    674.1K
 * Total Submissions: 1.5M
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of numCourses courses you have to take, labeled from 0 to
 * numCourses - 1. You are given an array prerequisites where prerequisites[i]
 * = [ai, bi] indicates that you must take course bi first if you want to take
 * course ai.
 * 
 * 
 * For example, the pair [0, 1], indicates that to take course 0 you have to
 * first take course 1.
 * 
 * 
 * Return true if you can finish all courses. Otherwise, return false.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: numCourses = 2, prerequisites = [[1,0]]
 * Output: true
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0. So it is possible.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
 * Output: false
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0, and to take course 0 you
 * should also have finished course 1. So it is impossible.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= numCourses <= 10^5
 * 0 <= prerequisites.length <= 5000
 * prerequisites[i].length == 2
 * 0 <= ai, bi < numCourses
 * All the pairs prerequisites[i] are unique.
 * 
 * 
 */

#include "common.hpp"

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        std::vector<std::vector<int>> graph (numCourses, std::vector<int>());
        for (auto &p : prerequisites) {
            graph.at(p.at(1)).push_back(p.at(0));
        }
        std::vector<bool> visited (numCourses, false);
        std::vector<bool> temp_visited (numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (!visit(i, graph, visited, temp_visited)) {
                return false;
            }
        }
        return true;
    }

private:
    bool visit(int node, const std::vector<std::vector<int>> &graph, std::vector<bool> &visited, std::vector<bool> &temp_visited) {
        if (visited[node]) return true;
        if (temp_visited[node]) return false;

        temp_visited[node] = true;

        for (auto &child : graph.at(node)) {
            int result = visit(child, graph, visited, temp_visited);
            if (!result) return false;
        }
        // this is crucial as there may be another path reach the same node
        temp_visited[node] = false;
        visited[node] = true;
        // for topological sort, we add node to the top of a list.
        return true;

    }
};
