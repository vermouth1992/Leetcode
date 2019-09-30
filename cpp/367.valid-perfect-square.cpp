/*
 * @lc app=leetcode id=367 lang=cpp
 *
 * [367] Valid Perfect Square
 *
 * https://leetcode.com/problems/valid-perfect-square/description/
 *
 * algorithms
 * Easy (40.37%)
 * Total Accepted:    126.4K
 * Total Submissions: 312.8K
 * Testcase Example:  '16'
 *
 * Given a positive integer num, write a function which returns True if num is
 * a perfect square else False.
 * 
 * Note: Do not use any built-in library function such as sqrt.
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: 16
 * Output: true
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 14
 * Output: false
 * 
 * 
 * 
 */
class Solution {
private:
    bool isPerfectSquareHelper(int num, int low, int high) {
        if (high - low <= 1) {
            if (low * low == num) return true;
            else return false;
        } else {
            int middle = (low + high) / 2;
            int middleSquare = middle * middle;
            if (middleSquare == num) return true;
            else if (middleSquare < num) return isPerfectSquareHelper(num, middle, high);
            else return isPerfectSquareHelper(num, low, middle);
        }
    }

public:
    bool isPerfectSquare(int num) {
        if (num < 0) return false;
        return isPerfectSquareHelper(num, 0, 46341);
    }
};
