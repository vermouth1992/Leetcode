/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 *
 * https://leetcode.com/problems/interleaving-string/description/
 *
 * algorithms
 * Medium (32.99%)
 * Total Accepted:    225.6K
 * Total Submissions: 665.9K
 * Testcase Example:  '"aabcc"\n"dbbca"\n"aadbbcbcac"'
 *
 * Given strings s1, s2, and s3, find whether s3 is formed by an interleaving
 * of s1 and s2.
 * 
 * An interleaving of two strings s and t is a configuration where they are
 * divided into non-empty substrings such that:
 * 
 * 
 * s = s1 + s2 + ... + sn
 * t = t1 + t2 + ... + tm
 * |n - m| <= 1
 * The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 +
 * t3 + s3 + ...
 * 
 * 
 * Note: a + b is the concatenation of strings a and b.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
 * Output: false
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s1 = "", s2 = "", s3 = ""
 * Output: true
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= s1.length, s2.length <= 100
 * 0 <= s3.length <= 200
 * s1, s2, and s3 consist of lowercase English letters.
 * 
 * 
 * 
 * Follow up: Could you solve it using only O(s2.length) additional memory
 * space?
 * 
 */

#include "common.hpp"

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        return this->isInterleaveHelper(s1, s2, s3, 0, 0);
    }

private:
    bool isInterleaveHelper(const string &s1, const string &s2, const string &s3,
                            int s1_index, int s2_index) {
        int s3_index = s1_index + s2_index;
        if (s3_index == s3.size()) {
            return true;
        }
        auto current_pair = std::make_pair(s1_index, s2_index);
        if (memoization.find(current_pair) != memoization.end()) {
            return memoization.at(current_pair);
        }
        int result;
        if (s1_index < s1.size() && s1.at(s1_index) == s3.at(s3_index)) {
            result = this->isInterleaveHelper(s1, s2, s3, s1_index + 1, s2_index);
            if (result) {
                memoization[current_pair] = true;
                return true;
            }
        }
        if (s2_index < s2.size() && s2.at(s2_index) == s3.at(s3_index)) {
            result = this->isInterleaveHelper(s1, s2, s3, s1_index, s2_index + 1);
            if (result) {
                memoization[current_pair] = true;
                return true;
            }
        }
        memoization[current_pair] = false;
        return false;
    }

    std::map<std::pair<int, int>, bool> memoization;
};
