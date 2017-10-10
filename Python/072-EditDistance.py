"""
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
"""

class Solution(object):
    def minDistance(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        >>> Solution().minDistance('aaa', 'a')
        2
        >>> Solution().minDistance('aaa', '')
        3
        >>> Solution().minDistance('', 'a')
        1
        >>> Solution().minDistance('sea', 'ate')
        3
        """
        approach = 'baseline_dp'
        if approach == 'baseline_dp':
            vec1 = [i for i in range(0, len(word1) + 1)]
            vec2 = [0 for i in range(0, len(word1) + 1)]
            for j in range(1, len(word2) + 1):
                vec2[0] = j
                for i in range(1, len(word1) + 1):
                    if word1[i - 1] == word2[j - 1]:
                        vec2[i] = vec1[i - 1]
                    else:
                        vec2[i] = min(vec1[i - 1], vec1[i], vec2[i - 1])
                        vec2[i] += 1
                vec1, vec2 = vec2, vec1
            return vec1[len(word1)]
        else:
            # better solution
            pass


