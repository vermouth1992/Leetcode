/*
 * @lc app=leetcode id=1025 lang=cpp
 *
 * [1025] Divisor Game
 *
 * https://leetcode.com/problems/divisor-game/description/
 *
 * algorithms
 * Easy (64.90%)
 * Total Accepted:    26.5K
 * Total Submissions: 40.7K
 * Testcase Example:  '2'
 *
 * Alice and Bob take turns playing a game, with Alice starting first.
 * 
 * Initially, there is a number N on the chalkboard.  On each player's turn,
 * that player makes a move consisting of:
 * 
 * 
 * Choosing any x with 0 < x < N and N % x == 0.
 * Replacing the number N on the chalkboard with N - x.
 * 
 * 
 * Also, if a player cannot make a move, they lose the game.
 * 
 * Return True if and only if Alice wins the game, assuming both players play
 * optimally.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 2
 * Output: true
 * Explanation: Alice chooses 1, and Bob has no more moves.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 3
 * Output: false
 * Explanation: Alice chooses 1, Bob chooses 1, and Alice has no more
 * moves.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= N <= 1000
 * 
 * 
 * 
 */

#include "common.hpp"

class Solution {
public:
    bool divisorGame(int N) {
        bool *result = new bool[N + 1];
        result[1] = false;
        for (size_t i = 2; i < N + 1; i++)
        {
            bool hasFalse = false;
            for (size_t j = 1; j <= sqrt(i); j++)
            {
                if (i % j == 0) {
                    if (!result[i - j]) {
                        hasFalse = true;
                        break;
                    }
                    if (j != 1 && (!result[i - i / j])) {
                        hasFalse = true;
                        break;
                    }
                }
            }
            if (hasFalse) {
                result[i] = true;
            } else {
                result[i] = false;
            }
        }
        bool outcome = result[N];
        delete []result;
        return outcome;
    }
};
