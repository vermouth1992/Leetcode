/*
 * @lc app=leetcode id=677 lang=cpp
 *
 * [677] Map Sum Pairs
 *
 * https://leetcode.com/problems/map-sum-pairs/description/
 *
 * algorithms
 * Medium (54.25%)
 * Total Accepted:    63.6K
 * Total Submissions: 113.8K
 * Testcase Example:  '["MapSum", "insert", "sum", "insert", "sum"]\n' +
  '[[], ["apple",3], ["ap"], ["app",2], ["ap"]]'
 *
 * Implement the MapSum class:
 * 
 * 
 * MapSum() Initializes the MapSum object.
 * void insert(String key, int val) Inserts the key-val pair into the map. If
 * the key already existed, the original key-value pair will be overridden to
 * the new one.
 * int sum(string prefix) Returns the sum of all the pairs' value whose key
 * starts with the prefix.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input
 * ["MapSum", "insert", "sum", "insert", "sum"]
 * [[], ["apple", 3], ["ap"], ["app", 2], ["ap"]]
 * Output
 * [null, null, 3, null, 5]
 * 
 * Explanation
 * MapSum mapSum = new MapSum();
 * mapSum.insert("apple", 3);  
 * mapSum.sum("ap");           // return 3 (apple = 3)
 * mapSum.insert("app", 2);    
 * mapSum.sum("ap");           // return 5 (apple + app = 3 + 2 = 5)
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= key.length, prefix.length <= 50
 * key and prefix consist of only lowercase English letters.
 * 1 <= val <= 1000
 * At most 50 calls will be made to insert and sum.
 * 
 * 
 */

#include "common.hpp"

struct TrieNode {
    int val;
    TrieNode *nodes[26];
    TrieNode(): val(0), nodes{nullptr} {}
};

class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new TrieNode();
    }
    
    void insert(string key, int val) {
        int prev_val = 0;
        if (words.find(key) != words.end()) {
            prev_val = words.at(key);
        }
        words[key] = val;

        TrieNode *curr = root;
        for (int i = 0; i < key.size(); i++) {
            int index = key[i] - 'a';
            if (curr->nodes[index] == nullptr) {
                curr->nodes[index] = new TrieNode();
            }
            curr->nodes[index]->val += val - prev_val;  // record cumulative sum.
            curr = curr->nodes[index];
        }
    }
    
    int sum(string prefix) {
        TrieNode *curr = root;
        for (int i = 0; i < prefix.size(); i++) {
            int index = prefix[i] - 'a';
            if (curr == nullptr) {
                return 0;
            } else if (i == prefix.size() - 1) {
                if (curr->nodes[index] == nullptr) return 0;
                else return curr->nodes[index]->val;
            } else {
                curr = curr->nodes[index];
            }
        }
        return 0;
    }

private:
    TrieNode* root {nullptr};
    map<string, int> words;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */

int main() {
    MapSum s;
    s.insert("apple", 3);
    std::cout << s.sum("appl") << std::endl;
}