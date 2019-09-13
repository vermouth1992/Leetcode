"""
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
"""

"""
How to use dynamic programming technique?
And the DP idea is :

If s[i] is '(', set longest[i] to 0,because any string end with '(' cannot be a valid one.

Else if s[i] is ')'

     If s[i-1] is '(', longest[i] = longest[i-2] + 2

     Else if s[i-1] is ')' and s[i-longest[i-1]-1] == '(', longest[i] = longest[i-1] + 2 + longest[i-longest[i-1]-2]

For example, input "()(())", at i = 5, longest array is [0,2,0,0,2,0], longest[5] = longest[4] + 2 + longest[1] = 6.
"""


class Solution(object):

    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        >>> Solution().longestValidParentheses(')()())')
        4
        >>> Solution().longestValidParentheses('(()()(')
        4
        >>> Solution().longestValidParentheses('(()())')
        6
        >>> Solution().longestValidParentheses("()(()")
        2
        >>> Solution().longestValidParentheses('())()()(())((()(()()(((()))((((())((()(())()())(()((((()))()(()))(())()(())(()((' + \
        '(((())((((((()())())(()(()((())()))(()))))))()(()))((((())()()()))()()()(((()(()())(()()(()(()' + \
        '()(((()))))))()()))())())((()()))))))((()))(((()((())()(()()))((())))()()())))))))()))))(()))))' + \
        '()))()))()((())))((()))(()))))))(((()))))))))()(()()()(())((())()))()()(())))()()))(()())()))(((()' + \
        '())()))((())((((()))(()(()(()()()(((())()(((((()))((()(((((())(()()))((((((((()(()(()(()(())))(())' + \
        '(()())())(()((((()(())((()(())))(())))()(((((()(()()(())))))))())(())(())(()()(((())))((()))(((((()))))())))()((()))())' + \
        ')))())))))((())(((((()()))((((())))(((()(()(())())(((()(()(()()()())))())()))((()((())())()()()(((())(((((()((((((()((()()))' + \
        ')((((())((()(((((((()(()((()()()(()(()())(()(()()((((())))()(((()())))(()()))()(()()()()(((((())(()))))((()))())))()((((((()))' + \
        '())))()(()))(())))((((()())(((((()()())(((((())(()())(()))))()(()()))()))))))())))(((())(()(()()))(()))()(((())))())((((()(((()' + \
        '))))))()(()(()))()()(()()))))))))((()))))))(())((()((()))()))((((((()())))))(()((())((((()))))(()(()()()()(()))()()(()(()))(()()' + \
        '(((((((()())(())(()())((())())()(()())((())()())())(()())))())))(())())())(())((()())(((()()))()))()()))()(()(())((((((((())))()' + \
        '((())((()((((((((((()))))(()(((((())(()(()())())))((())())))))()))(()((()()))((()((())()()()((()(())())((())())(()()(((())))))())' + \
        '()()(()))()())(()(()((())))((((()()(())))())(())(()(()(())())())(()()())()(())())))(()()(((())))((()()(((())()()(()())((((()()(()()' + \
        ')(()((((()(()()(()(()(((()((()())(()()))(()((((()(((((()))))()()))(((()((((((()(()()()()())()))(()(())))))((()(((()())())))(((()()))(()' + \
        '(()(((((((()()))(()(())))())()(())())(())(()))(())(()))()()(()()())))))()))()((())(((()((((((((())()()))())))((()())(')
        310
        """
        if len(s) == 0:
            return 0
        current_index = 0
        num_left_parenthese = 0
        current_max_length = 0
        start_index = 0
        while current_index < len(s):
            if num_left_parenthese == 0:
                if s[current_index] == ')':
                    current_index += 1
                    start_index = current_index
                else:
                    num_left_parenthese += 1
                    current_index += 1
            else:
                if s[current_index] == ')':
                    current_index += 1
                    num_left_parenthese -= 1
                    if num_left_parenthese == 0:
                        current_max_length = max(current_max_length, current_index - start_index)
                else:
                    current_index += 1
                    num_left_parenthese += 1
        # need to deal with end of string case, use stack
        if num_left_parenthese != 0:
            stack = []
            for i in range(start_index, len(s)):
                if s[i] == '(':
                    stack.append(i)
                else:
                    stack.pop()

            # the left index in stack is the unmatched
            right = len(s)
            while len(stack) != 0:
                left = stack.pop()
                if right - left - 1 > current_max_length:
                    current_max_length = right - left - 1
                right = left
        return current_max_length


