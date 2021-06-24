#
# @lc app=leetcode id=208 lang=python3
#
# [208] Implement Trie (Prefix Tree)
#
# https://leetcode.com/problems/implement-trie-prefix-tree/description/
#
# algorithms
# Medium (53.18%)
# Total Accepted:    430K
# Total Submissions: 803.2K
# Testcase Example:  '["Trie","insert","search","search","startsWith","insert","search"]\n' +
#  '[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]'
#
# A trie (pronounced as "try") or prefix tree is a tree data structure used to
# efficiently store and retrieve keys in a dataset of strings. There are
# various applications of this data structure, such as autocomplete and
# spellchecker.
# 
# Implement the Trie class:
# 
# 
# Trie() Initializes the trie object.
# void insert(String word) Inserts the string word into the trie.
# boolean search(String word) Returns true if the string word is in the trie
# (i.e., was inserted before), and false otherwise.
# boolean startsWith(String prefix) Returns true if there is a previously
# inserted string word that has the prefix prefix, and false otherwise.
# 
# 
# 
# Example 1:
# 
# 
# Input
# ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
# [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
# Output
# [null, null, true, false, true, null, true]
# 
# Explanation
# Trie trie = new Trie();
# trie.insert("apple");
# trie.search("apple");   // return True
# trie.search("app");     // return False
# trie.startsWith("app"); // return True
# trie.insert("app");
# trie.search("app");     // return True
# 
# 
# 
# Constraints:
# 
# 
# 1 <= word.length, prefix.length <= 2000
# word and prefix consist only of lowercase English letters.
# At most 3 * 10^4 calls in total will be made to insert, search, and
# startsWith.
# 
# 
#
class Trie:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.storage = {}
        

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        current_level = self.storage
        for w in word:
            if w not in current_level:
                current_level[w] = {}
            
            current_level = current_level[w]
        current_level['word'] = True

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        current_level = self.storage
        for w in word:
            if w not in current_level:
                return False
            current_level = current_level[w]

        return 'word' in current_level
        

    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        current_level = self.storage
        for w in prefix:
            if w not in current_level:
                return False
            current_level = current_level[w]
        
        return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
