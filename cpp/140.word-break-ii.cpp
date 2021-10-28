/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 *
 * https://leetcode.com/problems/word-break-ii/description/
 *
 * algorithms
 * Hard (36.21%)
 * Total Accepted:    380.5K
 * Total Submissions: 971.7K
 * Testcase Example:  '"catsanddog"\n["cat","cats","and","sand","dog"]'
 *
 * Given a string s and a dictionary of strings wordDict, add spaces in s to
 * construct a sentence where each word is a valid dictionary word. Return all
 * such possible sentences in any order.
 * 
 * Note that the same word in the dictionary may be reused multiple times in
 * the segmentation.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
 * Output: ["cats and dog","cat sand dog"]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "pineapplepenapple", wordDict =
 * ["apple","pen","applepen","pine","pineapple"]
 * Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
 * Explanation: Note that you are allowed to reuse a dictionary word.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
 * Output: []
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 20
 * 1 <= wordDict.length <= 1000
 * 1 <= wordDict[i].length <= 10
 * s and wordDict[i] consist of only lowercase English letters.
 * All the strings of wordDict are unique.
 * 
 * 
 */

#include "common.hpp"

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // trie and backtracking
        root = new TrieNode();
        for (auto &word: wordDict) {
            this->add(word);
        }
        std::vector<std::string> result;
        std::string curr;
        this->dfs(result, curr, s, 0, 0, root);
        return result;
    }

private:
    struct TrieNode {
        bool anchor;
        TrieNode **next;
        TrieNode(): anchor(false) {
            next = new TrieNode*[26];
            for (int i = 0; i < 26; i++) {
                next[i] = nullptr;
            }
        }
    };

    TrieNode *root;

    void add(const std::string &word) {
        TrieNode *curr = root;
        for (auto & c: word) {
            int index = c - 'a';
            // std::cout << index << std::endl;
            if (curr->next[index] == nullptr) {
                curr->next[index] = new TrieNode();
            }
            curr = curr->next[index];
        }
        curr->anchor = true;
    }

    void dfs(std::vector<string>&result, std::string &curr, const std::string &s, int start_index, int curr_index, TrieNode* node) {
        // base case
        if (curr_index == s.size()) {
            if (start_index == s.size()) {
                result.push_back(curr);
                return;
            } else {
                return;
            }
        }
        // find next node according to s
        char c = s.at(curr_index);
        TrieNode *next = node->next[c - 'a'];
        if (next == nullptr) return;  // no such word
        if (next->anchor) {
            // split here [start_index, curr_index]
            auto sub_string = s.substr(start_index, curr_index - start_index + 1);

            // std::cout << sub_string << std::endl;

            int inserted_size = 0;
            if (curr.size() != 0) {
                curr += " ";
                inserted_size += 1;
            }
            curr += sub_string;
            inserted_size += sub_string.size();
            this->dfs(result, curr, s, curr_index + 1, curr_index + 1, root);

            // pop back
            for (int i = 0; i < inserted_size; i++) {
                curr.pop_back();
            }

        }
        // not split or continue searching
        this->dfs(result, curr, s, start_index, curr_index + 1, next);
    }
};


int main(int argc, char const *argv[]) {
    std::vector<string> wordList {"cat","cats","and","sand","dog"};
    Solution().wordBreak("catsanddog", wordList);
    return 0;
}
