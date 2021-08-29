/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
 *
 * algorithms
 * Medium (48.68%)
 * Total Accepted:    208.3K
 * Total Submissions: 422.5K
 * Testcase Example:  '[1,2,3,0,2]'
 *
 * You are given an array prices where prices[i] is the price of a given stock
 * on the i^th day.
 * 
 * Find the maximum profit you can achieve. You may complete as many
 * transactions as you like (i.e., buy one and sell one share of the stock
 * multiple times) with the following restrictions:
 * 
 * 
 * After you sell your stock, you cannot buy stock on the next day (i.e.,
 * cooldown one day).
 * 
 * 
 * Note: You may not engage in multiple transactions simultaneously (i.e., you
 * must sell the stock before you buy again).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: prices = [1,2,3,0,2]
 * Output: 3
 * Explanation: transactions = [buy, sell, cooldown, buy, sell]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: prices = [1]
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= prices.length <= 5000
 * 0 <= prices[i] <= 1000
 * 
 * 
 */

#include "common.hpp"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // opt[i]: the optimal profit start from i
        std::vector<int> dp(prices.size(), 0);
        // last one
        dp.at(dp.size() - 1) = 0;
        if (prices.size() > 1) {
            dp.at(dp.size() - 2) = max(prices[prices.size() - 1] - prices[prices.size() - 2], 0);
        }
        if (prices.size() > 2) {
            dp.at(dp.size() - 3) = max(prices[prices.size() - 2] - prices[prices.size() - 3], dp.at(dp.size() - 2));
            dp.at(dp.size() - 3) = max(dp.at(dp.size() - 3), prices[prices.size() - 1] - prices[prices.size() - 3]);
        }
        for (int i = prices.size() - 4; i >= 0; i--) {
            dp.at(i) = max(dp.at(i + 1), prices.at(i + 1) - prices[i] + dp.at(i + 3));
        }
        // the space can be reduced to O(1) because we only need 4 variables
        return dp.at(0);
    }
};
