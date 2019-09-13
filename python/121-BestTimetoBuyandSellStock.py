"""
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Example 1:
Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
Example 2:
Input: [7, 6, 4, 3, 1]
Output: 0

In this case, no transaction is done, i.e. max profit = 0.
"""

"""
DP: Let opt(n) denotes the maximum profit when selling at day n, then
opt(n) = max(opt(n - 1) + f(n) - f(n - 1), f(n) - f(n - 1))
opt(1) = f(1) - f(0)
"""


class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        >>> Solution().maxProfit([7, 1, 5, 3, 6, 4])
        5
        >>> Solution().maxProfit([7, 6, 4, 3, 1])
        0
        """
        if len(prices) <= 1:
            return 0
        prev, max_Profit = 0, 0
        for i in range(1, len(prices)):
            prev = max(prices[i] - prices[i - 1], prev + prices[i] - prices[i - 1])
            if prev > max_Profit:
                max_Profit = prev
        return max_Profit
