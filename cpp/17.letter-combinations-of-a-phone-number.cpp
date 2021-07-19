/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (50.32%)
 * Total Accepted:    893.5K
 * Total Submissions: 1.8M
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent. Return the answer in
 * any order.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: digits = "23"
 * Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: digits = ""
 * Output: []
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: digits = "2"
 * Output: ["a","b","c"]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= digits.length <= 4
 * digits[i] is a digit in the range ['2', '9'].
 * 
 * 
 */

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        vector<string> keyboard {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string curr;
        if (digits.size() <= 0) return result;
        this->helper(result, curr, keyboard, digits, 0);
        return result;
    }

private:
    void helper(vector<string>& result, string &curr, vector<string> &keyboard, string &digits, int index) {
        string currentBoard = keyboard[digits[index] - '0' - 2];
        for (int i = 0; i < currentBoard.size(); i++)
        {
            // add to curr
            curr += currentBoard[i];
            if (index == digits.size() - 1) {
                result.push_back(string(curr));
            } else {
                helper(result, curr, keyboard, digits, index + 1);
            }
            // remove the last char
            curr.pop_back();
        }
    }
};
