/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 *
 * https://leetcode.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (30.03%)
 * Total Accepted:    425.5K
 * Total Submissions: 1.4M
 * Testcase Example:  '"(()"'
 *
 * Given a string containing just the characters '(' and ')', find the length
 * of the longest valid (well-formed) parentheses substring.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()".
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = ""
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= s.length <= 3 * 10^4
 * s[i] is '(', or ')'.
 * 
 * 
 */

#include "common.hpp"

class Solution {
public:
    int longestValidParentheses(string s) {
        // store the index of the left parenthesis
        std::stack<int> helper_stack;
        // the size of the substring end in position i
        std::vector<int> dp (s.size(), 0);
        int max_size = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s.at(i) == '(') {
                helper_stack.push(i);
            } else {
                // get the top
                if (!helper_stack.empty()) {
                    // the size of the current matching
                    int left_pos = helper_stack.top();
                    helper_stack.pop();
                    int curr_matching_size = i - left_pos + 1;
                    if (left_pos > 0) {
                        curr_matching_size += dp.at(left_pos - 1);
                    }
                    dp.at(i) = curr_matching_size;
                    max_size = max(max_size, curr_matching_size);
                }
            }
        }
        return max_size;
    }
};
