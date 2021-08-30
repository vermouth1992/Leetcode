/*
 * @lc app=leetcode id=901 lang=cpp
 *
 * [901] Online Stock Span
 *
 * https://leetcode.com/problems/online-stock-span/description/
 *
 * algorithms
 * Medium (61.68%)
 * Total Accepted:    100.5K
 * Total Submissions: 161.8K
 * Testcase Example:  '["StockSpanner","next","next","next","next","next","next","next"]\n' +
  '[[],[100],[80],[60],[70],[60],[75],[85]]'
 *
 * Design an algorithm that collects daily price quotes for some stock and
 * returns the span of that stock's price for the current day.
 * 
 * The span of the stock's price today is defined as the maximum number of
 * consecutive days (starting from today and going backward) for which the
 * stock price was less than or equal to today's price.
 * 
 * 
 * For example, if the price of a stock over the next 7 days were
 * [100,80,60,70,60,75,85], then the stock spans would be [1,1,1,2,1,4,6].
 * 
 * 
 * Implement the StockSpanner class:
 * 
 * 
 * StockSpanner() Initializes the object of the class.
 * int next(int price) Returns the span of the stock's price given that today's
 * price is price.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input
 * ["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
 * [[], [100], [80], [60], [70], [60], [75], [85]]
 * Output
 * [null, 1, 1, 1, 2, 1, 4, 6]
 * 
 * Explanation
 * StockSpanner stockSpanner = new StockSpanner();
 * stockSpanner.next(100); // return 1
 * stockSpanner.next(80);  // return 1
 * stockSpanner.next(60);  // return 1
 * stockSpanner.next(70);  // return 2
 * stockSpanner.next(60);  // return 1
 * stockSpanner.next(75);  // return 4, because the last 4 prices (including
 * today's price of 75) were less than or equal to today's price.
 * stockSpanner.next(85);  // return 6
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= price <= 10^5
 * At most 10^4 calls will be made to next.
 * 
 * 
 */

#include "common.hpp"

class StockSpanner {
public:
    StockSpanner() {
        m_index = 0;
    }
    
    int next(int price) {
        // if the element is greater than the top. Pop until find the one smaller. Then, push the current
        // O(N) because each element is pushed and popped at most once.
        while (!monotonic_stack.empty() && monotonic_stack.top().second <= price) {
            monotonic_stack.pop();
        }
        int prev_index = monotonic_stack.empty() ? -1 : monotonic_stack.top().first;
        int result = m_index - prev_index;
        // update
        monotonic_stack.push(std::make_pair(m_index, price));
        m_index += 1;
        return result;
    }

private:
    std::stack<std::pair<int, int>> monotonic_stack;
    int m_index;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
