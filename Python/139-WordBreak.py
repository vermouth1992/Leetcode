"""
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words. You may assume the dictionary does not contain duplicate words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".

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
    def wordBreak(self, s, wordDict):
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
        return vec[len(s)]

if __name__ == '__main__':
    s = 'aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa'
    dic = ["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]
    assert Solution().wordBreak(s, dic) == False
    s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
    dic = ["aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa","ba"]
    assert Solution().wordBreak(s, dic) == False
