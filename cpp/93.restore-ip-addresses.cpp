/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 *
 * https://leetcode.com/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (38.28%)
 * Total Accepted:    245.4K
 * Total Submissions: 632.4K
 * Testcase Example:  '"25525511135"'
 *
 * Given a string s containing only digits, return all possible valid IP
 * addresses that can be obtained from s. You can return them in any order.
 * 
 * A valid IP address consists of exactly four integers, each integer is
 * between 0 and 255, separated by single dots and cannot have leading zeros.
 * For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses and
 * "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP
 * addresses. 
 * 
 * 
 * Example 1:
 * Input: s = "25525511135"
 * Output: ["255.255.11.135","255.255.111.35"]
 * Example 2:
 * Input: s = "0000"
 * Output: ["0.0.0.0"]
 * Example 3:
 * Input: s = "1111"
 * Output: ["1.1.1.1"]
 * Example 4:
 * Input: s = "010010"
 * Output: ["0.10.0.10","0.100.1.0"]
 * Example 5:
 * Input: s = "101023"
 * Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= s.length <= 3000
 * s consists of digits only.
 * 
 * 
 */

#include "common.hpp"

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<string> curr {};
        this->helper(result, curr, 0, s);
        return result;
    }

private:
    void helper(vector<string> &result, vector<string> &curr, int currentIndex, string &s) {
        // base case
        if (currentIndex == s.size()) {
            if (curr.size() == 4) {
                string temp = "";
                for (int i = 0; i < curr.size(); i++) {
                    temp = temp + curr[i];
                    if (i != curr.size() - 1) {
                        temp = temp + '.';
                    }
                }
                result.push_back(temp);
            }
            return;
        }
        // add currentIndex to the previous string or start a new string
        bool append_to_prev = false;
        char current_char = s.at(currentIndex);

        if (curr.size() == 0) {
            append_to_prev = false;
        } else {
            auto last_string = curr.back();
            if (last_string.size() == 3) {
                append_to_prev = false;
            } else if (last_string.size() == 2) {
                // if adding the current is not valid
                if (last_string[0] == '1') {
                    append_to_prev = true;
                } else if (last_string[0] == '2') {
                    if (last_string[1] < '5') {
                        append_to_prev = true;
                    } else if (last_string[1] == '5') {
                        append_to_prev = current_char <= '5';
                    } else {
                        append_to_prev = false;
                    }
                } else {
                    append_to_prev = false;
                }
            } else if (last_string.size() == 1) {
                if (last_string[0] == '0') {
                    append_to_prev = false;
                } else {
                    append_to_prev = true;
                }
            }

            // std::cout << last_string << " " << append_to_prev << " " << start_new_string << std::endl;
        }
        
        if (append_to_prev) {
            curr.back().append(1, current_char);
            this->helper(result, curr, currentIndex + 1, s);
            curr.back().pop_back();
        }
        if (curr.size() < 4) {
            curr.push_back(string(1, current_char));
            this->helper(result, curr, currentIndex + 1, s);
            curr.pop_back();
        }
        return;       
    }
};


int main() {
    Solution().restoreIpAddresses("25525511135");
}