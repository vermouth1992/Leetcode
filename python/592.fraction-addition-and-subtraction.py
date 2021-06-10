#
# @lc app=leetcode id=592 lang=python3
#
# [592] Fraction Addition and Subtraction
#
# https://leetcode.com/problems/fraction-addition-and-subtraction/description/
#
# algorithms
# Medium (50.64%)
# Total Accepted:    23.7K
# Total Submissions: 46.7K
# Testcase Example:  '"-1/2+1/2"'
#
# Given a string expression representing an expression of fraction addition and
# subtraction, return the calculation result in string format.
# 
# The final result should be an irreducible fraction. If your final result is
# an integer, say 2, you need to change it to the format of a fraction that has
# a denominator 1. So in this case, 2 should be converted to 2/1.
# 
# 
# Example 1:
# 
# 
# Input: expression = "-1/2+1/2"
# Output: "0/1"
# 
# 
# Example 2:
# 
# 
# Input: expression = "-1/2+1/2+1/3"
# Output: "1/3"
# 
# 
# Example 3:
# 
# 
# Input: expression = "1/3-1/2"
# Output: "-1/6"
# 
# 
# Example 4:
# 
# 
# Input: expression = "5/3+1/3"
# Output: "2/1"
# 
# 
# 
# Constraints:
# 
# 
# The input string only contains '0' to '9', '/', '+' and '-'. So does the
# output.
# Each fraction (input and output) has the format ±numerator/denominator. If
# the first input fraction or the output is positive, then '+' will be
# omitted.
# The input only contains valid irreducible fractions, where the numerator and
# denominator of each fraction will always be in the range [1, 10]. If the
# denominator is 1, it means this fraction is actually an integer in a fraction
# format defined above.
# The number of given fractions will be in the range [1, 10].
# The numerator and denominator of the final result are guaranteed to be valid
# and in the range of 32-bit int.
# 
# 
#


def gcd(a, b):
  
    # Everything divides 0
    if (a == 0):
        return b
    if (b == 0):
        return a
  
    # base case
    if (a == b):
        return a
  
    # a is greater
    if (a > b):
        return gcd(a-b, b)
    return gcd(a, b-a)

class Fraction(object):
    def __init__(self, num, den):
        self.num = num
        self.den = den
        assert self.den > 0

    def __add__(self, other):
        new_den = self.den * other.den
        new_num = self.num * other.den + other.num * self.den
        if new_num == 0:
            new_den = 1
            return Fraction(new_num, new_den)
        
        if new_num < 0:
            g = gcd(new_den, -new_num)
        else:
            g = gcd(new_den, new_num)

        return Fraction(new_num // g, new_den // g)


    @classmethod
    def from_str(cls, string):
        num, den = string.split('/')
        num = int(num)
        den = int(den)
        return cls(num, den)

    def __repr__(self):
        return str(self.num) + '/' + str(self.den)


class Solution:
    def fractionAddition(self, expression: str) -> str:
        numbers = []
        prev_ptr = 0
        next_ptr = 1
        while next_ptr < len(expression):
            if expression[next_ptr] == '-' or expression[next_ptr] == '+':
                numbers.append(Fraction.from_str(expression[prev_ptr:next_ptr]))
                prev_ptr = next_ptr
            next_ptr += 1

        numbers.append(Fraction.from_str(expression[prev_ptr:next_ptr]))

        total = Fraction(0, 1)
        for num in numbers:
            total = total + num

        print(numbers)

        return str(total)


if __name__ == '__main__':
    expression = "-1/2+1/2"
    print(Solution().fractionAddition(expression))

