/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (66.20%)
 * Total Accepted:    800.7K
 * Total Submissions: 1.2M
 * Testcase Example:  '3'
 *
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * Example 1:
 * Input: n = 3
 * Output: ["((()))","(()())","(())()","()(())","()()()"]
 * Example 2:
 * Input: n = 1
 * Output: ["()"]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 8
 * 
 * 
 */

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string curr;
        this->helper(result, curr, 0, n);
        return result;
    }

private:
    void helper(vector<string> &result, string &curr, int currentLeft, int remainingLeft) {
        if (currentLeft == 0 && remainingLeft == 0) {
            result.push_back(string(curr));
            return;
        }

        if (currentLeft == 0) {
            curr += '(';
            this->helper(result, curr, currentLeft + 1, remainingLeft - 1);
            curr.pop_back();
        } else {
            if (remainingLeft == 0) {
                curr += ')';
                this->helper(result, curr, currentLeft - 1, remainingLeft);
                curr.pop_back();
            } else {
                curr += '(';
                this->helper(result, curr, currentLeft + 1, remainingLeft - 1);
                curr.pop_back();
                curr += ')';
                this->helper(result, curr, currentLeft - 1, remainingLeft);
                curr.pop_back();
            }
        }
    }

};
