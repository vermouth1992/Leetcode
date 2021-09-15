/*
 * @lc app=leetcode id=468 lang=cpp
 *
 * [468] Validate IP Address
 *
 * https://leetcode.com/problems/validate-ip-address/description/
 *
 * algorithms
 * Medium (25.26%)
 * Total Accepted:    109.6K
 * Total Submissions: 426.9K
 * Testcase Example:  '"172.16.254.1"'
 *
 * Given a string IP, return "IPv4" if IP is a valid IPv4 address, "IPv6" if IP
 * is a valid IPv6 address or "Neither" if IP is not a correct IP of any type.
 * 
 * A valid IPv4 address is an IP in the form "x1.x2.x3.x4" where 0 <= xi <= 255
 * and xi cannot contain leading zeros. For example, "192.168.1.1" and
 * "192.168.1.0" are valid IPv4 addresses but "192.168.01.1", while
 * "192.168.1.00" and "192.168@1.1" are invalid IPv4 addresses.
 * 
 * A valid IPv6 address is an IP in the form "x1:x2:x3:x4:x5:x6:x7:x8"
 * where:
 * 
 * 
 * 1 <= xi.length <= 4
 * xi is a hexadecimal string which may contain digits, lower-case English
 * letter ('a' to 'f') and upper-case English letters ('A' to 'F').
 * Leading zeros are allowed in xi.
 * 
 * 
 * For example, "2001:0db8:85a3:0000:0000:8a2e:0370:7334" and
 * "2001:db8:85a3:0:0:8A2E:0370:7334" are valid IPv6 addresses, while
 * "2001:0db8:85a3::8A2E:037j:7334" and
 * "02001:0db8:85a3:0000:0000:8a2e:0370:7334" are invalid IPv6 addresses.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: IP = "172.16.254.1"
 * Output: "IPv4"
 * Explanation: This is a valid IPv4 address, return "IPv4".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: IP = "2001:0db8:85a3:0:0:8A2E:0370:7334"
 * Output: "IPv6"
 * Explanation: This is a valid IPv6 address, return "IPv6".
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: IP = "256.256.256.256"
 * Output: "Neither"
 * Explanation: This is neither a IPv4 address nor a IPv6 address.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: IP = "2001:0db8:85a3:0:0:8A2E:0370:7334:"
 * Output: "Neither"
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: IP = "1e1.4.5.6"
 * Output: "Neither"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * IP consists only of English letters, digits and the characters '.' and ':'.
 * 
 * 
 */

#include "common.hpp"

class Solution {
public:
    string validIPAddress(string IP) {
        if (IP.size() < 5) return neither;
        // O(1) time by looking at the first 5 
        for (int i = 0; i < 5; i++) {
            if (IP.at(i) == '.') return this->validIPv4Address(IP);
            else if (IP.at(i) == ':') return this->validIPv6Address(IP);
        }
        return neither;
    }

private:
    const std::string ipv4 = "IPv4";
    const std::string ipv6 = "IPv6";
    const std::string neither = "Neither";
    std::string validIPv4Address(const std::string &IP) {
        int num_numbers = 0;
        int start = 0;
        int number_index = 0;
        char next_possible_max = 0;
        for (int i = 0; i < IP.size(); i++) {
            if (IP.at(i) == '.') {
                // verify the number IP[start:i)
                number_index = 0;
                num_numbers += 1;
                // at most 3 dots
                if (num_numbers > 3 || i == IP.size() - 1) return neither;
            } else if (IP.at(i) < '0' || IP.at(i) > '9') {
                return neither;
            } else {
                if (number_index == 0) {
                    if (IP.at(i) > '2') return neither;
                    else if (IP.at(i) == '2') {
                        next_possible_max = '5';
                    } else {
                        next_possible_max = '9';
                    }
                } else if (number_index == 1) {
                    if (IP.at(i - 1) == '0') return neither;
                    else {
                        if (IP.at(i) > next_possible_max) return neither;
                        // the next_possible_max is the same for the next number
                        if (IP.at(i) != '5') next_possible_max = '9';
                    }
                } else if (number_index == 2) {
                    if (IP.at(i) > next_possible_max) return neither;
                } else {
                    // more than 3 digits
                    return neither;
                }
                number_index += 1;
            }
        }
        if (num_numbers != 3) return neither;
        return ipv4;
    }

    std::string validIPv6Address(const std::string &IP) {
        int start = 0;
        int num_numbers = 0;
        for (int i = 0; i < IP.size(); i++) {
            if (IP.at(i) == ':') {
                int current_length = i - start;
                if (current_length > 4 || current_length < 1) return neither;
                num_numbers += 1;
                if (num_numbers > 7) return neither;
                start = i + 1;
            } else if (IP.at(i) >= '0' && IP.at(i) <= '9') {
                // do nothing
            } else if (IP.at(i) >= 'a' && IP.at(i) <= 'f') {
                // do nothing
            } else if (IP.at(i) >= 'A' && IP.at(i) <= 'F') {
                // do nothing
            } else {
                return neither;
            }
        }
        int current_length = IP.size() - start;
        if (current_length > 4 || current_length < 1) return neither;
        if (num_numbers < 7) return neither;
        return ipv6;
    }
};
