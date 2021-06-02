#
# @lc app=leetcode id=556 lang=python3
#
# [556] Next Greater Element III
#
# https://leetcode.com/problems/next-greater-element-iii/description/
#
# algorithms
# Medium (33.41%)
# Total Accepted:    69.5K
# Total Submissions: 207.9K
# Testcase Example:  '12'
#
# Given a positive integer n, find the smallest integer which has exactly the
# same digits existing in the integer n and is greater in value than n. If no
# such positive integer exists, return -1.
# 
# Note that the returned integer should fit in 32-bit integer, if there is a
# valid answer but it does not fit in 32-bit integer, return -1.
# 
#  
# Example 1:
# Input: n = 12
# Output: 21
# Example 2:
# Input: n = 21
# Output: -1
# 
# 
# Constraints:
# 
# 
# 1 <= n <= 2^31 - 1
# 
# 
#
class Solution:
    def nextGreaterElement(self, n: int) -> int:
        # step 1: turn integer into a list of digits
        digits = []
        m = n
        previous_digit = None
        while m != 0:
            last_digit = m % 10
            digits.append(last_digit)
            m = m // 10
            if previous_digit is not None:
                if previous_digit > last_digit:
                    # find a inversion. Find the smallest digit in the list that is greater then last_digit
                    min_digit = digits[-2]
                    min_index = len(digits) - 2
                    for i, num in enumerate(digits[:-1]):
                        if num > last_digit and num < min_digit:
                            min_digit = num
                            min_index = i

                    min_digit = digits.pop(min_index)
                    digits = sorted(digits)

                    # construct the new output
                    m = m * 10 + min_digit
                    for d in digits:
                        m = m * 10 + d
                        if m > ((1 << 31) - 1):
                            return -1

                    return m
            
            previous_digit = last_digit

        return -1


if __name__ == '__main__':
    print(Solution().nextGreaterElement(12))
    print(Solution().nextGreaterElement(12345))
    print(Solution().nextGreaterElement(12354))
    print(Solution().nextGreaterElement(245623754))
    print(Solution().nextGreaterElement(2147483476))