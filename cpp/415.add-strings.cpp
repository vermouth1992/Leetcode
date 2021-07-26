/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 *
 * https://leetcode.com/problems/add-strings/description/
 *
 * algorithms
 * Easy (48.91%)
 * Total Accepted:    323.1K
 * Total Submissions: 653.2K
 * Testcase Example:  '"11"\n"123"'
 *
 * Given two non-negative integers, num1 and num2 represented as string, return
 * the sum of num1 and num2 as a string.
 * 
 * You must solve the problem without using any built-in library for handling
 * large integers (such as BigInteger). You must also not convert the inputs to
 * integers directly.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: num1 = "11", num2 = "123"
 * Output: "134"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: num1 = "456", num2 = "77"
 * Output: "533"
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: num1 = "0", num2 = "0"
 * Output: "0"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= num1.length, num2.length <= 10^4
 * num1 and num2 consist of only digits.
 * num1 and num2 don't have any leading zeros except for the zero itself.
 * 
 * 
 */

#include "common.hpp"

class Solution {
public:
    string addStrings(string num1, string num2) {
        int size = std::max(num1.size(), num2.size());
        string result = "";
        int i = 1;
        char q = 0;
        char remainder = 0;
        while (i <= size) {
            int s1_idx = num1.size() - i;
            int s2_idx = num2.size() - i;
            char temp1, temp2;
            if (s1_idx >= 0) {
                temp1 = num1.at(s1_idx) - '0';
            } else {
                temp1 = 0;
            }
            if (s2_idx >= 0) {
                temp2 = num2.at(s2_idx) - '0';
            } else {
                temp2 = 0;
            }
            char temp3 = temp1 + temp2 + q;
            q = temp3 / 10;
            remainder = temp3 % 10;
            result.insert(result.begin(), remainder + '0');
            i++;
        }
        if (q == 1) {
            result.insert(result.begin(), '1');
        }
        return result;
    }
};

int main() {
    std::cout << Solution().addStrings("11", "222") << std::endl;
}
