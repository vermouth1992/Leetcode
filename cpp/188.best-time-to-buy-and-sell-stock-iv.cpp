/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/
 *
 * algorithms
 * Hard (30.46%)
 * Total Accepted:    199.3K
 * Total Submissions: 636.2K
 * Testcase Example:  '2\n[2,4,1]'
 *
 * You are given an integer array prices where prices[i] is the price of a
 * given stock on the i^th day, and an integer k.
 * 
 * Find the maximum profit you can achieve. You may complete at most k
 * transactions.
 * 
 * Note: You may not engage in multiple transactions simultaneously (i.e., you
 * must sell the stock before you buy again).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: k = 2, prices = [2,4,1]
 * Output: 2
 * Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit
 * = 4-2 = 2.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: k = 2, prices = [3,2,6,5,0,3]
 * Output: 7
 * Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit
 * = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3),
 * profit = 3-0 = 3.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= k <= 100
 * 0 <= prices.length <= 1000
 * 0 <= prices[i] <= 1000
 * 
 * 
 */


#include "common.hpp"

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        return maxProfit_v2(k, prices);
    }

    int maxProfit_v1(int k, vector<int>& prices) {
        if (prices.size() < 2) return 0;
        if (k < 1) return 0;
        std::vector<std::vector<int>> dp (prices.size(), std::vector<int> (k + 1, 0));
        for (int l = 1; l <= k; l++) {
            for (int sell_day = 1; sell_day < prices.size(); sell_day++) {
                int max_profit = dp.at(sell_day - 1).at(l);  // doesn't do anything
                int current_min = prices.at(sell_day - 1);
                // this can be optimized. No need to compute dp.at(m - 1).at(l - 1)) - current_min each time.
                for (int m = sell_day - 1; m >= 0; m--) {
                    current_min = min(current_min, prices[m]);
                    if (m >= 1) {
                        max_profit = max(max_profit, prices[sell_day] - current_min + dp.at(m - 1).at(l - 1));
                    } else {
                        max_profit = max(max_profit, prices[sell_day] - current_min);
                    }
                    
                }
                dp.at(sell_day).at(l) = max_profit;
            }
        }
        return dp.at(prices.size() - 1).at(k);
    }

    int maxProfit_v2(int k, vector<int>& prices) {
        if (prices.size() < 2) return 0;
        if (k < 1) return 0;
        std::vector<std::vector<int>> dp (prices.size(), std::vector<int> (k + 1, 0));
        for (int l = 1; l <= k; l++) {
            int current_max = dp.at(0).at(l - 1) - prices.at(0);
            for (int sell_day = 1; sell_day < prices.size(); sell_day++) {
                int max_profit = dp.at(sell_day - 1).at(l);  // doesn't do anything
                int current = dp.at(sell_day - 1).at(l - 1) - prices.at(sell_day - 1);
                current_max = max(current_max, current);
                max_profit = max(max_profit, prices[sell_day] + current_max);
                dp.at(sell_day).at(l) = max_profit;
            }
        }
        return dp.at(prices.size() - 1).at(k);
    }
    
};


int main() {
    std::vector<int> prices {3, 3, 5, 0, 0, 3, 1, 4};
    std::cout << Solution().maxProfit(2, prices);
    return 0;
}
