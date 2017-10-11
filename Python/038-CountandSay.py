"""
The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

Example 1:

Input: 1
Output: "1"
Example 2:

Input: 4
Output: "1211"
"""

class Solution(object):
    def generateNext(self, number_str):
        if len(number_str) == 1:
            return '1' + number_str
        next_number_str = ''
        currentNum = 1
        for i in range(1, len(number_str)):
            if number_str[i] == number_str[i - 1]:
                currentNum += 1
            else:
                next_number_str += str(currentNum) + str(number_str[i - 1])
                currentNum = 1
        next_number_str += str(currentNum) + str(number_str[-1])
        return next_number_str

    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        >>> Solution().countAndSay(4)
        '1211'
        >>> Solution().countAndSay(5)
        '111221'
        >>> Solution().countAndSay(1)
        '1'
        """
        current = '1'
        for i in range(1, n):
            current = self.generateNext(current)
        return current
        
