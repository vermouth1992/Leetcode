#
# @lc app=leetcode id=518 lang=python3
#
# [518] Coin Change 2
#
# https://leetcode.com/problems/coin-change-2/description/
#
# algorithms
# Medium (52.59%)
# Total Accepted:    195.5K
# Total Submissions: 371.6K
# Testcase Example:  '5\n[1,2,5]'
#
# You are given an integer array coins representing coins of different
# denominations and an integer amount representing a total amount of money.
# 
# Return the number of combinations that make up that amount. If that amount of
# money cannot be made up by any combination of the coins, return 0.
# 
# You may assume that you have an infinite number of each kind of coin.
# 
# The answer is guaranteed to fit into a signed 32-bit integer.
# 
# 
# Example 1:
# 
# 
# Input: amount = 5, coins = [1,2,5]
# Output: 4
# Explanation: there are four ways to make up the amount:
# 5=5
# 5=2+2+1
# 5=2+1+1+1
# 5=1+1+1+1+1
# 
# 
# Example 2:
# 
# 
# Input: amount = 3, coins = [2]
# Output: 0
# Explanation: the amount of 3 cannot be made up just with coins of 2.
# 
# 
# Example 3:
# 
# 
# Input: amount = 10, coins = [10]
# Output: 1
# 
# 
# 
# Constraints:
# 
# 
# 1 <= coins.length <= 300
# 1 <= coins[i] <= 5000
# All the values of coins are unique.
# 0 <= amount <= 5000
# 
# 
#

## Better solution to use table DP instead of LRU cache

from typing import List, Tuple
import functools

class Solution:
    @functools.lru_cache(maxsize=None)
    def change_tuple(self, amount: int, coins: Tuple[int]) -> int:
        if amount == 0:
            return 1
        if len(coins) == 1:
            # base case
            if amount % coins[0] == 0:
                return 1
            else:
                return 0
        else:
            # recursion
            max_num_first_coin = amount // coins[0]
            if max_num_first_coin == 0:
                return 0
            changes = 0
            for i in range(max_num_first_coin + 1):
                changes += self.change_tuple(amount - i * coins[0], coins[1:])
            return changes

    def change(self, amount: int, coins: List[int]) -> int:
        coins = sorted(coins)
        return self.change_tuple(amount, tuple(coins))
        

if __name__ == '__main__':
    print(Solution().change(5, [1, 2, 5]))