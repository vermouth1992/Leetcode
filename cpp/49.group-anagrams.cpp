/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (60.22%)
 * Total Accepted:    1.7M
 * Total Submissions: 2.5M
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * Given an array of strings strs, group the anagrams together. You can return
 * the answer in any order.
 * 
 * An Anagram is a word or phrase formed by rearranging the letters of a
 * different word or phrase, typically using all the original letters exactly
 * once.
 * 
 * 
 * Example 1:
 * Input: strs = ["eat","tea","tan","ate","nat","bat"]
 * Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
 * Example 2:
 * Input: strs = [""]
 * Output: [[""]]
 * Example 3:
 * Input: strs = ["a"]
 * Output: [["a"]]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= strs.length <= 10^4
 * 0 <= strs[i].length <= 100
 * strs[i] consists of lowercase English letters.
 * 
 * 
 */

#include "common.hpp"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // sort each string and construct a map.
        std::map<std::string, std::vector<std::string>> result;
        for (auto &str : strs) {  // O(N)
            std::vector<char> data(str.begin(), str.end());
            std::sort(data.begin(), data.end());  // O(nlogn)

            std::string sorted_data(data.begin(), data.end());

            if (result.find(sorted_data) == result.end()) {
                result[sorted_data] = std::vector<std::string>();
            }
            result[sorted_data].push_back(str);  // O(log N)
        }
        // convert result to vector
        vector<vector<string>> vec_result;
        for (auto &r : result) {
            vec_result.push_back(r.second);
        }
        return vec_result;
    }
};
