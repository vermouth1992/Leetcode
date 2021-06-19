#
# @lc app=leetcode id=714 lang=python3
#
# [714] Best Time to Buy and Sell Stock with Transaction Fee
#
# https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/
#
# algorithms
# Medium (58.35%)
# Total Accepted:    114.2K
# Total Submissions: 195.2K
# Testcase Example:  '[1,3,2,8,4,9]\n2'
#
# You are given an array prices where prices[i] is the price of a given stock
# on the i^th day, and an integer fee representing a transaction fee.
# 
# Find the maximum profit you can achieve. You may complete as many
# transactions as you like, but you need to pay the transaction fee for each
# transaction.
# 
# Note: You may not engage in multiple transactions simultaneously (i.e., you
# must sell the stock before you buy again).
# 
# 
# Example 1:
# 
# 
# Input: prices = [1,3,2,8,4,9], fee = 2
# Output: 8
# Explanation: The maximum profit can be achieved by:
# - Buying at prices[0] = 1
# - Selling at prices[3] = 8
# - Buying at prices[4] = 4
# - Selling at prices[5] = 9
# The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
# 
# 
# Example 2:
# 
# 
# Input: prices = [1,3,7,5,10,3], fee = 3
# Output: 6
# 
# 
# 
# Constraints:
# 
# 
# 1 <= prices.length <= 5 * 10^4
# 1 <= prices[i] < 5 * 10^4
# 0 <= fee < 5 * 10^4
# 
# 
#

from typing import List

class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        # a means the cash
        # b means the cash - price[i]. It is the same as max_{i < j} cash[i] - price[i]

        a = [0]
        b = [-prices[0]]
        for i in range(1, len(prices)):
            a.append(max(a[i - 1], b[i - 1] + prices[i] - fee))
            b.append(max(b[i - 1], a[i - 1] - prices[i]))
        return a[len(prices) - 1]
