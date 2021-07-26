/*
 * @lc app=leetcode id=306 lang=cpp
 *
 * [306] Additive Number
 *
 * https://leetcode.com/problems/additive-number/description/
 *
 * algorithms
 * Medium (29.84%)
 * Total Accepted:    62.3K
 * Total Submissions: 207.9K
 * Testcase Example:  '"112358"'
 *
 * Additive number is a string whose digits can form additive sequence.
 * 
 * A valid additive sequence should contain at least three numbers. Except for
 * the first two numbers, each subsequent number in the sequence must be the
 * sum of the preceding two.
 * 
 * Given a string containing only digits '0'-'9', write a function to determine
 * if it's an additive number.
 * 
 * Note: Numbers in the additive sequence cannot have leading zeros, so
 * sequence 1, 2, 03 or 1, 02, 3 is invalid.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "112358"
 * Output: true
 * Explanation: The digits can form an additive sequence: 1, 1, 2, 3, 5,
 * 8. 
 * 1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "199100199"
 * Output: true
 * Explanation: The additive sequence is: 1, 99, 100, 199. 
 * 1 + 99 = 100, 99 + 100 = 199
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * num consists only of digits '0'-'9'.
 * 1 <= num.length <= 35
 * 
 * 
 * Follow up:
 * How would you handle overflow for very large input integers?
 * 
 */

#include "common.hpp"

class Solution {
public:
    bool isAdditiveNumber(string num) {
        if (num.size() < 3) return false;
        return this->helper("-1", "-1", "-1", 0, num);
    }

private:
    int stringAddEqual(const string &s1, const string &s2, const string &s3) {
        // return 1 if s1 + s2 > s3; 0 if s1 + s2 == s3; -1 if s1 + s2 < s3
        // step 1: add s1 and s2
        auto s1_add_s2 = this->stringAdd(s1, s2);
        // std::cout << s1 << " + " << s2 << " = " << s1_add_s2 << std::endl;
        bool result = this->stringCompare(s1_add_s2, s3);
        // std::cout << s1_add_s2 << " compare to " << s3 << " = " << result << std::endl;
        return result;
    }

    string stringAdd(const string &num1, const string &num2) {
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

    int stringCompare(const string &s1, const string &s2) {
        if (s1.size() != s2.size()) {
            if (s1.size() > s2.size()) return 1;
            else return -1;
        }
        for (int i = 0; i < s1.size(); i++) {
            if (s1.at(i) > s2.at(i)) return 1;
            else if (s1.at(i) < s2.at(i)) return -1;
        }
        return 0;
    }

    bool helper(string first, string second, string third, int currentIndex, string &num) {
        // std::cout << first << " " << second << " " << third << " " << currentIndex << std::endl;
        // base case
        if (currentIndex == num.size()) {
            if (third == "-1") return false;
            return this->stringAddEqual(first, second, third) == 0;
        }

        string currentNum {num[currentIndex]};
        if (first == "-1") {
            // currentIndex must be zero
            return this->helper(currentNum, second, third, currentIndex + 1, num);
        }
        // first is not -1. has been set.
        else if (second == "-1") {
            // two case. add the current number to the first or second
            if (first == "0") {
                // must add to the second
                return this->helper(first, currentNum, third, currentIndex + 1, num);
            } else {
                // add to the first
                bool result = this->helper(first + currentNum, second, third, currentIndex + 1, num);
                if (result) return true;
                // add to the second
                return this->helper(first, currentNum, third, currentIndex + 1, num);
            }
        }
        if (third == "-1") {
            // two cases. add to the second or third
            if (second == "0") {
                return this->helper(first, second, currentNum, currentIndex + 1, num);
            } else {
                bool result = this->helper(first, second + currentNum, third, currentIndex + 1, num);
                if (result) return true;
                return this->helper(first, second, currentNum, currentIndex + 1, num);
            }
        }
        // add to the third or start a new number
        if (this->stringAddEqual(first, second, third) > 0) {
            if (third != "0") {
                return this->helper(first, second, third + currentNum, currentIndex + 1, num);
            } else {
                return false;
            }
        } else if (this->stringAddEqual(first, second, third) < 0) {
            return false;
        } else {
            return this->helper(second, third, currentNum, currentIndex + 1, num);
        }
        
    }
};

int main() {
    std::cout << Solution().isAdditiveNumber("199001200") << std::endl;
    return 0;
}
