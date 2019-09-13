"""
Implement pow(x, n).
"""

class Solution(object):
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        if n == 0:
            return 1
        elif n < 0:
            return 1.0 / self.myPow(x, -n)
        else:
            if n == 1:
                return x
            elif n == 2:
                return x * x
            elif n % 2 == 0:
                result = self.myPow(x, n // 2)
                return result * result
            else:
                return x * self.myPow(x, n - 1)
                