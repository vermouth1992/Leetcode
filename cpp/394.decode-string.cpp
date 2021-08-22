/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 *
 * https://leetcode.com/problems/decode-string/description/
 *
 * algorithms
 * Medium (53.39%)
 * Total Accepted:    362.9K
 * Total Submissions: 671.7K
 * Testcase Example:  '"3[a]2[bc]"'
 *
 * Given an encoded string, return its decoded string.
 * 
 * The encoding rule is: k[encoded_string], where the encoded_string inside the
 * square brackets is being repeated exactly k times. Note that k is guaranteed
 * to be a positive integer.
 * 
 * You may assume that the input string is always valid; No extra white spaces,
 * square brackets are well-formed, etc.
 * 
 * Furthermore, you may assume that the original data does not contain any
 * digits and that digits are only for those repeat numbers, k. For example,
 * there won't be input like 3a or 2[4].
 * 
 * 
 * Example 1:
 * Input: s = "3[a]2[bc]"
 * Output: "aaabcbc"
 * Example 2:
 * Input: s = "3[a2[c]]"
 * Output: "accaccacc"
 * Example 3:
 * Input: s = "2[abc]3[cd]ef"
 * Output: "abcabccdcdcdef"
 * Example 4:
 * Input: s = "abc3[cd]xyz"
 * Output: "abccdcdcdxyz"
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 30
 * s consists of lowercase English letters, digits, and square brackets
 * '[]'.
 * s is guaranteed to be a valid input.
 * All the integers in s are in the range [1, 300].
 * 
 * 
 */

#include "common.hpp"

class Solution {
public:
    string decodeString(string s) {
        std::stack<char> char_stack;
        for (auto &c : s) {
            if (c != ']') {
                char_stack.push(c);
            } else {
                // perform reduce
                // 1. pop until we find "[" as the operand
                // 2. pop until the c is not a number.
                // 3. push the result into the stack
                std::string operand;
                while (char_stack.top() != '[') {
                    char top = char_stack.top();
                    operand.push_back(top);  // in the reverse order
                    char_stack.pop();
                }

                char_stack.pop(); // pop "["
                std::string num_str;
                while (!char_stack.empty() && char_stack.top() >= '0' && char_stack.top() <= '9') {
                    num_str.insert(num_str.begin(), char_stack.top());
                    char_stack.pop();
                }

                int num = std::stoi(num_str);

                for (size_t i = 0; i < num; i++) {
                    for (auto it = operand.rbegin(); it != operand.rend(); it++) {
                        char_stack.push(*it);
                    }
                }
            }
        }
        // return the stack as a string
        std::string result;
        while (!char_stack.empty()) {
            result.insert(result.begin(), char_stack.top());
            char_stack.pop();
        }
        return result;
    }
};


int main() {
    std::cout << Solution().decodeString("3[a]2[bc]");
}