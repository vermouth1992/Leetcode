"""
You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)

Example 2:
coins = [2], amount = 3
return -1.

Note:
You may assume that you have an infinite number of each kind of coin.
"""

class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        >>> Solution().coinChange([1, 2, 5], 11)
        3
        >>> Solution().coinChange([2], 3)
        -1
        """
        vec_0 = [0]
        for i in range(1, amount + 1):
            if i % coins[0] == 0:
                vec_0.append(i // coins[0])
            else:
                vec_0.append(-1)
        vec_1 = [0] * (amount + 1)
        for coin in coins[1:]:
            for i in range(1, amount + 1):
                if i < coin:
                    vec_1[i] = vec_0[i]
                else:
                    if vec_0[i] == -1:
                        if vec_1[i - coin] == -1:
                            vec_1[i] = -1
                        else:
                            vec_1[i] = vec_1[i - coin] + 1
                    else:
                        if vec_1[i - coin] == -1:
                            vec_1[i] = vec_0[i]
                        else:
                            vec_1[i] = min(vec_0[i], vec_1[i - coin] + 1)
            vec_0, vec_1 = vec_1, vec_0
        return vec_0[amount]
