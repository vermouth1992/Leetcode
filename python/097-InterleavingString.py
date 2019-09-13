"""
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
"aabc"
"abad"
"aabcabad"

"cbcccbabbccbbcccbbbcabbbabcababbbbbbaccaccbabbaacbaabbbc"
"abcbbcaababccacbaaaccbabaabbaaabcbababbcccbbabbbcbbb"
"abcbcccbacbbbbccbcbcacacbbbbacabbbabbcacbcaabcbaaacbcbbbabbbaacacbbaaaabccbcbaabbbaaabbcccbcbabababbbcbbbcbb"
"""

"""
We use traditional dfs/bfs
"""

class Solution(object):
    def isInterleave(self, s1, s2, s3):
        """
        :type s1: str
        :type s2: str
        :type s3: str
        :rtype: bool
        >>> Solution().isInterleave('aabcc', 'dbbca', 'aadbbcbcac')
        True
        >>> Solution().isInterleave('aabcc', 'dbbca', 'aadbbbaccc')
        False
        >>> Solution().isInterleave('aabc', 'abad', 'aabcabad')
        True
        >>> a = 'cbcccbabbccbbcccbbbcabbbabcababbbbbbaccaccbabbaacbaabbbc'
        >>> b = 'abcbbcaababccacbaaaccbabaabbaaabcbababbcccbbabbbcbbb'
        >>> c = 'abcbcccbacbbbbccbcbcacacbbbbacabbbabbcacbcaabcbaaacbcbbbabbbaacacbbaaaabccbcbaabbbaaabbcccbcbabababbbcbbbcbb'
        >>> Solution().isInterleave(a, b, c)
        True
        """
        if len(s1) + len(s2) != len(s3):
            return False
        elif len(s1) == 0:
            return s2 == s3
        elif len(s2) == 0:
            return s1 == s3
        stack = []
        stack.append((0, 0))
        while len(stack) != 0:
            i, j = stack.pop()
            # case 1: one of them has reached the end
            if i == len(s1):
                if s2[j:] == s3[i+j:]:
                    return True
                elif len(stack) == 0:
                    return False
            elif j == len(s2):
                if s1[i:] == s3[i+j:]:
                    return True
                elif len(stack) == 0:
                    return False
            else:
                if s1[i] == s2[j]:
                    if s1[i] == s3[i + j]:
                        stack.append((i + 1, j))
                        stack.append((i, j + 1))
                    elif len(stack) == 0:
                        return False
                elif s1[i] == s3[i + j]:
                    stack.append((i + 1, j))
                elif s2[j] == s3[i + j]:
                    stack.append((i, j + 1))
                elif len(stack) == 0:
                    return False
        assert False, "Shouldn't reach here"
        return False
