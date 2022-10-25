/*
 * @lc app=leetcode id=1662 lang=cpp
 *
 * [1662] Check If Two String Arrays are Equivalent
 *
 * https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/description/
 *
 * algorithms
 * Easy (82.27%)
 * Total Accepted:    232.5K
 * Total Submissions: 279.3K
 * Testcase Example:  '["ab", "c"]\n["a", "bc"]'
 *
 * Given two string arrays word1 and word2, return true if the two arrays
 * represent the same string, and false otherwise.
 * 
 * A string is represented by an array if the array elements concatenated in
 * order forms the string.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
 * Output: true
 * Explanation:
 * word1 represents string "ab" + "c" -> "abc"
 * word2 represents string "a" + "bc" -> "abc"
 * The strings are the same, so return true.
 * 
 * Example 2:
 * 
 * 
 * Input: word1 = ["a", "cb"], word2 = ["ab", "c"]
 * Output: false
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
 * Output: true
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= word1.length, word2.length <= 10^3
 * 1 <= word1[i].length, word2[i].length <= 10^3
 * 1 <= sum(word1[i].length), sum(word2[i].length) <= 10^3
 * word1[i] and word2[i] consist of lowercase letters.
 * 
 * 
 */

#include "common.hpp"



class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int word1WordIndex = 0;
        int word1CharIndex = 0;
        int word2WordIndex = 0;
        int word2CharIndex = 0;

        while (true) {
            // both of them reaches the end
            if (word1WordIndex >= word1.size() && word2WordIndex >= word2.size()) {
                return true;
            }
            // one of them reaches the end
            if (word1WordIndex >= word1.size() || word2WordIndex >= word2.size()) {
                return false;
            }
            // compare the current char
            if (word1.at(word1WordIndex).at(word1CharIndex) == word2.at(word2WordIndex).at(word2CharIndex)) {
                // get next pos
                word1CharIndex += 1;
                if (word1CharIndex == word1.at(word1WordIndex).length()) {
                    word1WordIndex += 1;
                    word1CharIndex = 0;
                }
                word2CharIndex += 1;
                if (word2CharIndex == word2.at(word2WordIndex).length()) {
                    word2WordIndex += 1;
                    word2CharIndex = 0;
                }
            } else {
                return false;
            }
        }
        
    }

};
