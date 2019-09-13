"""
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. You may assume the dictionary does not contain duplicate words.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].

UPDATE (2017/1/4):
The wordDict parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes.
"""

_end = '_end_'

def make_trie(words):
    root = dict()
    for word in words:
        current_dict = root
        for letter in reversed(word):
            current_dict = current_dict.setdefault(letter, {})
        current_dict[_end] = _end
    return root


class Solution(object):
    def wordBreakJudge(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        >>> Solution().wordBreak('leetcode', wordDict=['leet', 'code'])
        True
        >>> Solution().wordBreak('leetcode', wordDict=['leet', 'cod'])
        False
        >>> Solution().wordBreak('leetcode', wordDict=['leet', 'cod', 'e'])
        True
        """
        # first we make a trie data structure for fast search
        reversed_trie = make_trie(wordDict)
        vec = [True] + [False] * len(s)
        for i in range(len(s)):
            words = reversed_trie
            currentIndex = i
            while currentIndex >= 0:
                if s[currentIndex] not in words:
                    break
                else:
                    words = words[s[currentIndex]]
                    if _end in words and vec[currentIndex] == True:
                        vec[i + 1] = True
                        break
                    currentIndex -= 1
        return vec[len(s)], reversed_trie
    
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: List[str]
        >>> s = "catsanddog"
        >>> dictionary = ["cat", "cats", "and", "sand", "dog"]
        >>> set(Solution().wordBreak(s, dictionary)) == set(["cats and dog", "cat sand dog"])
        True
        """
        # sanity check, for case where a char in s is not in dict. This is really boring
        canBeBreak, reversed_trie = self.wordBreakJudge(s, wordDict)
        if canBeBreak is False:
            return []

        # first we make a trie data structure for fast search
        vec_index = [[[-1]]] + [[] for i in range(len(s))]
        for i in range(len(s)):
            words = reversed_trie
            currentIndex = i
            while currentIndex >= 0:
                if s[currentIndex] not in words:
                    break
                else:
                    words = words[s[currentIndex]]
                    if _end in words and len(vec_index[currentIndex]) != 0:
                        for w in vec_index[currentIndex]:
                            vec_index[i + 1].append(w[:] + [i + 1])
                    currentIndex -= 1
        result = []
        for index_lst in vec_index[len(s)]:
            string = s[0:index_lst[1]]
            for i in range(1, len(index_lst) - 1):
                string += ' ' + s[index_lst[i]:index_lst[i+1]]
            result.append(string)
        return result


