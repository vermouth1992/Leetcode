/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (31.72%)
 * Total Accepted:    2.4M
 * Total Submissions: 7.6M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string s, find the length of the longest substring without repeating
 * characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 * Notice that the answer must be a substring, "pwke" is a subsequence and not
 * a substring.
 * 
 * 
 * Example 4:
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
 * 0 <= s.length <= 5 * 10^4
 * s consists of English letters, digits, symbols and spaces.
 * 
 * 
 */

#include "common.hpp"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1) return s.size();
        std::unordered_map<char, int> char_to_index;
        int maxLength = 0;
        int currentStart = 0;
        for (int i = 0; i < s.size(); i++) {
            // if the next char in the index, readjust start index and form a new substring
            if (char_to_index.find(s[i]) != char_to_index.end()) {
                int repeatIndex = char_to_index.at(s[i]);
                if (repeatIndex >= currentStart) {
                    // the end of a non-repeat substring
                    int currentLength = i - currentStart;
                    if (currentLength > maxLength) {
                        maxLength = currentLength;
                    }
                    // the next valid substring
                    currentStart = repeatIndex + 1;
                }
            }
            char_to_index[s[i]] = i;
        }
        // the last substring
        int currentLength = s.size() - currentStart;
        if (currentLength > maxLength) {
            maxLength = currentLength;
        }
        return maxLength;
    }
};
