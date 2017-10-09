"""
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
"""

"""
The DP solution has many edge cases with 0.
"""

class Solution(object):
    def hasTwoWaysToDecode(self, number):
        return number > 10 and number <= 26 and number != 20

    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        >>> Solution().numDecodings('12')
        2
        >>> Solution().numDecodings('120')
        1
        >>> Solution().numDecodings('122')
        3
        >>> Solution().numDecodings('012')
        0
        >>> Solution().numDecodings('')
        0
        >>> Solution().numDecodings('301')
        0
        >>> Solution().numDecodings('12120')
        3
        """
        if len(s) == 0:
            return 0
        if s[0] == '0':
            return 0
        if len(s) < 2:
            return len(s)
        prev = 1
        number = int(s[0:2])
        if self.hasTwoWaysToDecode(number):
            curr = 2
        elif s[1] == '0' and int(s[0]) > 2:
            return 0
        else:
            curr = 1

        for i in range(2, len(s)):
            if s[i] == '0':
                if s[i - 1] != '1' and s[i - 1] != '2':
                    return 0
                else:
                    next_c = prev
            else:
                if self.hasTwoWaysToDecode(int(s[i-1:i+1])):
                    next_c = prev + curr
                else:
                    next_c = curr
            prev = curr
            curr = next_c
        return curr
        


