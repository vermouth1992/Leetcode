/*
 * @lc app=leetcode id=838 lang=cpp
 *
 * [838] Push Dominoes
 *
 * https://leetcode.com/problems/push-dominoes/description/
 *
 * algorithms
 * Medium (50.23%)
 * Total Accepted:    42.9K
 * Total Submissions: 82.8K
 * Testcase Example:  '"RR.L"'
 *
 * There are n dominoes in a line, and we place each domino vertically upright.
 * In the beginning, we simultaneously push some of the dominoes either to the
 * left or to the right.
 * 
 * After each second, each domino that is falling to the left pushes the
 * adjacent domino on the left. Similarly, the dominoes falling to the right
 * push their adjacent dominoes standing on the right.
 * 
 * When a vertical domino has dominoes falling on it from both sides, it stays
 * still due to the balance of the forces.
 * 
 * For the purposes of this question, we will consider that a falling domino
 * expends no additional force to a falling or already fallen domino.
 * 
 * You are given a string dominoes representing the initial state where:
 * 
 * 
 * dominoes[i] = 'L', if the i^th domino has been pushed to the left,
 * dominoes[i] = 'R', if the i^th domino has been pushed to the right, and
 * dominoes[i] = '.', if the i^th domino has not been pushed.
 * 
 * 
 * Return a string representing the final state.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: dominoes = "RR.L"
 * Output: "RR.L"
 * Explanation: The first domino expends no additional force on the second
 * domino.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: dominoes = ".L.R...LR..L.."
 * Output: "LL.RR.LLRRLL.."
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == dominoes.length
 * 1 <= n <= 10^5
 * dominoes[i] is either 'L', 'R', or '.'.
 * 
 * 
 */

#include "common.hpp"

class Solution {
public:
    string pushDominoes(string dominoes) {
        char left_domino = 'L';
        int left_ptr = 0;
        int right_ptr = 0;
        while (left_ptr < dominoes.size())
        {
            // find the right domino not equal to '.'
            while (right_ptr < dominoes.size() && dominoes[right_ptr] == '.')
            {
                right_ptr += 1;
            }
            if (right_ptr == dominoes.size()) {
                // at the end. if the left is right. push all to the right. otherwise, stand still
                if (left_domino == 'R') {
                    for (size_t i = left_ptr; i < right_ptr; i++)
                    {
                        dominoes[i] = 'R';
                    }
                }
                left_ptr = right_ptr;
            } else {
                if (right_ptr > left_ptr) {
                    if (left_domino == 'L') {
                        // L....L
                        if (dominoes[right_ptr] == 'L') {
                            for (size_t i = left_ptr; i < right_ptr; i++)
                            {
                                dominoes[i] = 'L';
                            }
                        } // else they stand still: L....R
                    } else if (left_domino == 'R') {
                        // R.....R
                        if (dominoes[right_ptr] == 'R') {
                            for (size_t i = left_ptr; i < right_ptr; i++)
                            {
                                dominoes[i] = 'R';
                            }
                        } else {
                            // R.....L
                            int temp_left = left_ptr;
                            int temp_right = right_ptr - 1;
                            while (temp_left < temp_right)
                            {
                                dominoes[temp_left] = 'R';
                                dominoes[temp_right] = 'L';
                                temp_left += 1;
                                temp_right -= 1;
                            }
                        }
                    }
                }
                
                left_domino = dominoes[right_ptr];
                right_ptr += 1;
                left_ptr = right_ptr;
            }
        }
        return dominoes;
    }
};

int main() {
    std::cout << Solution().pushDominoes("RR.L") << std::endl;
}