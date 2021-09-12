/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 *
 * https://leetcode.com/problems/basic-calculator/description/
 *
 * algorithms
 * Hard (38.42%)
 * Total Accepted:    240K
 * Total Submissions: 611.9K
 * Testcase Example:  '"1 + 1"'
 *
 * Given a string s representing a valid expression, implement a basic
 * calculator to evaluate it, and return the result of the evaluation.
 * 
 * Note: You are not allowed to use any built-in function which evaluates
 * strings as mathematical expressions, such as eval().
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "1 + 1"
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = " 2-1 + 2 "
 * Output: 3
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "(1+(4+5+2)-3)+(6+8)"
 * Output: 23
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 3 * 10^5
 * s consists of digits, '+', '-', '(', ')', and ' '.
 * s represents a valid expression.
 * '+' is not used as a unary operation.
 * '-' could be used as a unary operation but it has to be inside
 * parentheses.
 * There will be no two consecutive operators in the input.
 * Every number and running calculation will fit in a signed 32-bit integer.
 * 
 * 
 */

#include "common.hpp"


class Hybrid {
public:
    Hybrid(int operand): m_operand(operand), m_is_operand(true) {

    }
    Hybrid(char operator_char): m_operator(operator_char), m_is_operand(false) {

    }

    bool is_operand() const {
        return m_is_operand;
    }

    char get_operator() const {
        if (is_operand()) throw std::runtime_error("It is an operand\n");
        return m_operator;
    }

    int get_operand() const {
        if (!is_operand()) throw std::runtime_error("It is an operator\n");
        return m_operand;
    }

private:
    int m_operand;
    char m_operator;
    bool m_is_operand;
};
 
class Solution {
public:
    int calculate(string s) {
        std::stack<Hybrid> operand_stack;
        int index = 0;
        while (index < s.size()) {
            if (s.at(index) == ' ') {
                index += 1;
            } else if (s.at(index) == '+' || s.at(index) == '-' || s.at(index) == '(') {
                operand_stack.push(Hybrid(s.at(index)));
                index += 1;
            } else if (s.at(index) == ')') {
                // perform reduction
                int result = 0;
                while (true) {
                    // pop the next number
                    if (!operand_stack.top().is_operand()) {
                        // must be '('
                        operand_stack.pop();
                        break;
                    }

                    int operand = operand_stack.top().get_operand();
                    operand_stack.pop();
                    // pop the next operator
                    char operator_ = operand_stack.top().get_operator();
                    if (operator_ == '+') {
                        result += operand;
                        operand_stack.pop();
                    } else if (operator_ == '-') {
                        result -= operand;
                        operand_stack.pop();
                    } else if (operator_ == '(') {
                        result += operand;
                        operand_stack.pop();
                        break;
                    }  else {
                        throw std::runtime_error("Error");
                    }
                }
                // push the result back on the stack
                operand_stack.push(Hybrid(result));
                index += 1;
            } else {
                // read next number
                int current = 0;
                while (index < s.size() && s.at(index) >= '0' && s.at(index) <= '9') {
                    current = current * 10 + (int) (s.at(index) - '0');
                    index += 1;
                }
                operand_stack.push(Hybrid(current));
            }
        }
        // reduce the rest
        int result = 0;
        while (true) {
            // pop the next number
            if (operand_stack.empty()) break;

            int operand = operand_stack.top().get_operand();
            operand_stack.pop();
            // pop the next operator
            if (operand_stack.empty()) {
                result += operand;
                break;
            }
            char operator_ = operand_stack.top().get_operator();
            if (operator_ == '+') {
                result += operand;
                operand_stack.pop();
            } else if (operator_ == '-') {
                result -= operand;
                operand_stack.pop();
            } else {
                throw std::runtime_error("Error");
            }
        }
        return result;
    }
};


int main() {
    std::cout << Solution().calculate("-1+1");
}