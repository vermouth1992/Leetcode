/*
 * @lc app=leetcode id=1239 lang=cpp
 *
 * [1239] Maximum Length of a Concatenated String with Unique Characters
 *
 * https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/description/
 *
 * algorithms
 * Medium (50.35%)
 * Total Accepted:    161.4K
 * Total Submissions: 309K
 * Testcase Example:  '["un","iq","ue"]'
 *
 * You are given an array of strings arr. A string s is formed by the
 * concatenation of a subsequence of arr that has unique characters.
 * 
 * Return the maximum possible length of s.
 * 
 * A subsequence is an array that can be derived from another array by deleting
 * some or no elements without changing the order of the remaining elements.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = ["un","iq","ue"]
 * Output: 4
 * Explanation: All the valid concatenations are:
 * - ""
 * - "un"
 * - "iq"
 * - "ue"
 * - "uniq" ("un" + "iq")
 * - "ique" ("iq" + "ue")
 * Maximum length is 4.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr = ["cha","r","act","ers"]
 * Output: 6
 * Explanation: Possible longest valid concatenations are "chaers" ("cha" +
 * "ers") and "acters" ("act" + "ers").
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
 * Output: 26
 * Explanation: The only string in arr has all 26 characters.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 16
 * 1 <= arr[i].length <= 26
 * arr[i] contains only lowercase English letters.
 * 
 * 
 */

#include "common.hpp"

class Solution {
public:
    int maxLength(vector<string>& arr) {
        std::vector<bool> char_mask (26, false);
        int max_length = 0;
        this->backtrack(arr, 0, char_mask, 0, max_length);
        return max_length;
    }

private:
    void backtrack(const vector<string>& arr, int current_index, std::vector<bool> &char_mask, int current_length, int &max_length) {
        // base case
        if (current_index == arr.size()) {
            if (current_length > max_length) {
                max_length = current_length;
            }
            return;
        }

        // add i-th
        bool compatible = true;
        int stop_index;
        for (stop_index = 0; stop_index < arr.at(current_index).length(); stop_index++) {
            char c = arr.at(current_index).at(stop_index);
            if (char_mask[c - 'a']) {
                compatible = false;
                break;
            } else {
                char_mask[c - 'a'] = true;
            }
        }

        if (compatible) {
            backtrack(arr, current_index + 1, char_mask, current_length + arr.at(current_index).length(), max_length);
        } 

        // remove char from mask
        for (int k = 0; k < stop_index; k++) {
            char c = arr.at(current_index).at(k);
            char_mask[c - 'a'] = false;
        }

        // do not add it
        backtrack(arr, current_index + 1, char_mask, current_length, max_length);
        
    }
};
